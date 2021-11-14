const express = require('express');
const bcrypt = require('bcryptjs');
const User = require('../models/userModel');

const router = new express.Router();

//? register a new user.
router.post('/register', async (req, res) => {
  // make sure everything is passed ie, name,email,password
  var { name, email, password } = req.body;
  email = email.toLowerCase();
  if (!(name && email && password)) {
    return res.status(400).send('pass in name, email, password as JSON object');
  }

  // check if user already exists
  const userAlreadyExists = await User.findOne({ email });
  if (userAlreadyExists) {
    return res.status(409).send('User already exist, Please Login');
  }

  // encrypt password
  const encryptedPassword = await bcrypt.hash(password, 10);

  // save new user to DB
  const user = new User({ user: name, email, password: encryptedPassword });

  try {
    await user.save();
    res.status(201).send('user ' + user.user + ' saved.');
    console.log(user);
  } catch (e) {
    res.status(400).send(e);
  }
  // res.status(200).send('success');
});

module.exports = router;

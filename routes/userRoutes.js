require('dotenv').config();
const express = require('express');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
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
    res.status(201).send('new user ' + user.user + ' registered.');
    console.log(user);
  } catch (e) {
    res.status(400).send(e);
  }
});

//? login route
router.post('/login', async (req, res) => {
  try {
    const { email, password } = req.body;

    // find user by using email and do auth
    User.findOne({ email }, (err, user) => {
      // no user found with the given email
      if (user == null) {
        return res.status(400).send('No user found, Please Register.');
      }

      // check password match with found user and passed password
      bcrypt.compare(password, user.password).then((passwordMatched) => {
        if (passwordMatched) {
          // give a jwt
          const accessToken = jwt.sign(
            { userId: user._id },
            process.env.ACCESS_TOKEN_SECRET
          );

          return res.status(200).send({ accessToken });
        } else {
          return res.status(400).send('wrong password');
        }
      });
    });
  } catch (e) {
    res.status(400).send(e);
  }
});

module.exports = router;

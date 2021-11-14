const express = require('express');
const User = require('../models/userModel');

const router = new express.Router();

//? register a new user.
router.post('/register', async (req, res) => {
  const user = new User(req.body);
  console.log(req.body);
  try {
    await user.save();
    res.status(201).send('user ' + user.user + ' saved.');
    console.log(user);
  } catch (e) {
    res.status(400).send(e);
  }
});

module.exports = router;

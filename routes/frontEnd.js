require('dotenv').config();
const jwt = require('jsonwebtoken');
const path = require('path');
const express = require('express');

const { dirname } = require('path');

const router = new express.Router();

//? middle ware function where it will check if the JWT that the user has send is valid or not.
var authenticateJWT = function (req, res, next) {
  //! "Bearer JWT" authorization from req header.
  const authHeader = req.headers['authorization'];
  var token = authHeader && authHeader.split(' ')[1]; //if there is a jwt token passed then return the token else UNDEFINED, the split(' ')[1] will get the token part from the string passed in the Header "Bearer KEY"

  //! "cookie" based authorization from req header.
  //? if there is jwt in req cookie then that is the token
  if (req.cookies.authorization != undefined) token = req.cookies.authorization;

  if (token == null) return res.redirect('/login'); // if no token is passed then no access granted login

  jwt.verify(token, process.env.ACCESS_TOKEN_SECRET, (err, user) => {
    if (err) return res.sendStatus(403); // you have a token but it is not valid
    req.user = user; // user => the decrypted value which was inside the JWT
    next();
  });
};

//? frontend html serving routes
router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/index.html'));
});

router.get('/about', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/about.html'));
});

router.get('/post', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/post.html'));
});

router.get('/login', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/login.html'));
});

router.get('/admin', authenticateJWT, (req, res) => {
  res.sendFile(path.join(__dirname, '../guardedPages/admin.html'));
});

router.get('/*', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/404.html'));
});

module.exports = router;

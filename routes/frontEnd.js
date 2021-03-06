const { authenticateJWT } = require('../middleware/authJWT');
const path = require('path');
const express = require('express');

const { dirname } = require('path');

const router = new express.Router();

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

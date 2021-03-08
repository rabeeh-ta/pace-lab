const path = require('path');
const express = require('express');

const router = new express.Router();

//? fontend serve er
router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/index.html'));
});

router.get('/about', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/about.html'));
});
router.get('/*', (req, res) => {
  res.sendFile(path.join(__dirname, '../public/src/404.html'));
});

module.exports = router;

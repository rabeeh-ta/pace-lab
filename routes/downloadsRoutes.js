const express = require('express');
const path = require('path');

const router = new express.Router();

router.get('/download/:sub/:programNo', (req, res) => {
  var currentPath = path.join(
    __dirname,
    '..',
    'downloads',
    req.params.sub,
    req.params.programNo
  );

  res.sendFile(`${currentPath}`);
});

module.exports = router;

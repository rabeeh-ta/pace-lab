const express = require('express');
const path = require('path');
const fs = require('fs');

const router = new express.Router();

router.get('/download/:sub/:programNo', (req, res) => {
  const currentPath = path.join(
    __dirname,
    '..',
    'downloads',
    req.params.sub,
    req.params.programNo
  );

  res.sendFile(`${currentPath}`);
});

router.get('/download/ls', (req, res) => {
  let dirs = [];
  let files = [];
  const currentPath = path.join(__dirname, '..', 'downloads');

  // search directories
  fs.readdirSync(currentPath).forEach((dir) => {
    if (!(dir[0] == '.')) dirs.push(dir);
  });

  //search files
  dirs.forEach((dir, index) => {
    let subFiles = [];
    fs.readdirSync(currentPath + '/' + dir).forEach((file) => {
      if (!(file[0] == '.')) subFiles.push(file);
    });
    files[index] = subFiles;
  });

  res.send(`${dirs} \n ${files}`);
});

module.exports = router;

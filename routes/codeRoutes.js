const express = require('express');
const path = require('path');
const { authenticateJWT } = require('../middleware/authJWT');
const Code = require('../models/codeModel');
const Trash = require('../models/trashModel');
const User = require('../models/userModel');

const router = new express.Router();

router.get('/download/:programNo', (req, res) => {
  var currentPath = path.join(
    __dirname,
    '..',
    'downloads',
    req.params.programNo
  );

  res.sendFile(`${currentPath}`);
});

//? create a new code file
router.post('/code', async (req, res) => {
  const code = new Code(req.body);

  try {
    await code.save();
    res.status(201).send(code);
  } catch (e) {
    res.status(400).send(e);
  }
});

//? Read all code files
router.get('/codes', async (req, res) => {
  try {
    const codes = await Code.find().sort({ posted: 'desc' });
    res.status(200).send(codes);
  } catch (e) {
    res.status(400).send(e);
  }
});

//? get one by ID
router.get('/codes/:id', async (req, res) => {
  const _id = req.params.id;
  try {
    const code = await Code.findById(_id);
    if (!code) {
      return res.status(404).send({ error: 'The Code post does not exist.' });
    }
    res.status(200).send(code);
  } catch (e) {
    res.status(500).send(e);
  }
});

//? delete a code file
router.delete('/codes/:id', authenticateJWT, async (req, res) => {
  const _id = req.params.id; // the id of the code needs to  be deleted
  const uid = req.user.userId; // the users id who is logged in now

  var trashSchema = {}; // the object to save to trash

  try {
    const deletedCode = await Code.findByIdAndDelete(_id).lean();
    // const deletedCode = await Code.findById(_id).lean();
    if (deletedCode) {
      const user = await User.findById(uid); // get the user info with id
      trashSchema = deletedCode;
      delete trashSchema._id; // delete the id field
      trashSchema.deletedOn = Date.now(); // adding two new fields
      trashSchema.deletedBy = user.user; // name of the user.
      const trash = await new Trash(trashSchema).save(); // save the deleted code to trash.
    }

    if (!deletedCode) {
      return res.status(404).send({ response: 'Code file not found.' });
    }

    res
      .status(200)
      .send({ response: 'Deleted and Moved to Recently deleted.' });
  } catch (e) {
    res.status(500).send(e);
    console.log(e);
  }
});

//? update a file
router.put('/codes/:id', async (req, res) => {
  const _id = req.params.id;
  const updates = Object.keys(req.body);
  const updateCode = req.body;
  //   console.log(updates);
  try {
    let code = await Code.findById(_id);

    if (!code) {
      return res.status(404).send({ response: 'Code file not found' });
    }

    // console.log(code.author);
    // console.log(updateCode.description);
    console.log(code);
    updates.forEach((update) => {
      code[update] = updateCode.update;
    });
    console.log(code);

    res.status(404).send({ response: 'updating a code is under maintenance' });
  } catch (e) {
    res.status(500).send(e);
  }
});

//! trash bin routes

//? Read all codes recently deleted
router.get('/trashBin', async (req, res) => {
  try {
    const trash = await Trash.find().sort({ posted: 'desc' });
    res.status(200).send(trash);
  } catch (e) {
    res.status(400).send(e);
  }
});

router.delete('/trashBin/:id', async (req, res) => {
  const _id = req.params.id;

  try {
    const deletedFromBin = await Trash.findByIdAndDelete(_id);

    if (!deletedFromBin) {
      return res.status(404).send({ response: 'Code file not found.' });
    }

    res
      .status(200)
      .send({ response: 'Deleted and Moved to Recently deleted.' });
  } catch (e) {
    res.status(500).send(e);
    console.log(e);
  }
});

module.exports = router;

const express = require('express');
const Code = require('../models/codeModel');

const router = express.Router();

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
router.delete('/codes/:id', async (req, res) => {
  const _id = req.params.id;
  try {
    const found = await Code.findByIdAndDelete(_id);

    if (!found) {
      return res.status(404).send({ response: 'Code file not found.' });
    }

    res.status(200).send({ response: 'Deletion Successful' });
  } catch (e) {
    res.status(500).send(e);
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

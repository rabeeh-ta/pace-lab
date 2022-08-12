const mongoose = require('mongoose');

const codeSchema = new mongoose.Schema({
  title: {
    type: String,
    required: true,
    trim: true,
  },
  description: {
    type: String,
    trim: true,
    required: true,
  },
  code: {
    type: String,
    required: true,
  },
  sem: {
    type: Number,
    min: 1,
    max: 8,
    required: true,
  },
  tag: {
    type: String,
    trim: true,
  },
  author: {
    type: String,
    default: 'anonymous',
    trim: true,
  },
  date: {
    type: Date,
    default: Date.now,
  },
});

module.exports = mongoose.model('Code', codeSchema);

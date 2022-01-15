const mongoose = require('mongoose');

const trashSchema = new mongoose.Schema({
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
  author: {
    type: String,
    default: 'anonymous',
    trim: true,
  },
  deletedBy: {
    type: String,
    default: 'anonymous',
    trim: true,
  },
  deletedOn: {
    type: Date,
    default: Date.now,
  },
  date: {
    type: Date,
    required: true,
  },
});

module.exports = mongoose.model('Trash', trashSchema);

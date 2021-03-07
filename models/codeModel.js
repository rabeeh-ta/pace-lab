const mongoose = require('mongoose');

const codeSchema = new mongoose.Schema('Code', {
  title: {
    type: String,
    required: true,
  },
  description: {
    type: String,
    trim: true,
  },
  code: {
    type: String,
    required: true,
  },
  author: {
    type: String,
    default: 'anonymous',
  },
  posted: {
    type: Date,
    default: Date.now,
  },
});

module.exports = mongoose.model('Code', codeSchema);

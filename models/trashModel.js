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
  deletedBy: {
    type: String,
    default: 'anonymous',
    trim: true,
  },
  dateOn: {
    type: Date,
    default: Date.now,
  },
});

module.exports = mongoose.model('Trash', trashSchema);

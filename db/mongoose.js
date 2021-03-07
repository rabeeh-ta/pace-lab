const mongoose = require('mongoose');

mongoose
  .connect(
    'mongodb+srv://rabeeh:rabeeh@codeshare@codeshare.8orqr.mongodb.net/codeshare?retryWrites=true&w=majority',
    { useNewUrlParser: true, useCreateIndex: true, useUnifiedTopology: true }
  )
  .then(() => {
    console.log('Mongodb Connection');
  })
  .catch((e) => {
    console.log(e);
  });

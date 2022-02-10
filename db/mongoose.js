const mongoose = require('mongoose');

mongoose
  .connect(
    'mongodb+srv://rabeeh:rabeeh9895@prod-cluster.ctha1.mongodb.net/devMode?retryWrites=true&w=majority',
    { useNewUrlParser: true, useCreateIndex: true, useUnifiedTopology: true }
  )
  .then(() => {
    console.log('Mongodb Connected');
  })
  .catch((e) => {
    console.log(e);
  });

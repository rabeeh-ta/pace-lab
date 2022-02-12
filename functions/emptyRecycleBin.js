require('dotenv').config();
const mongoose = require('mongoose');

mongoose
  .connect(
    `mongodb+srv://rabeeh:${process.env.MONGO_PASSWORD}@prod-cluster.ctha1.mongodb.net/codeShare?retryWrites=true&w=majority`,
    { useNewUrlParser: true, useCreateIndex: true, useUnifiedTopology: true }
  )
  .then(() => {
    console.log('Mongodb Connected');
    process.exit();
  })
  .catch((e) => {
    console.log(e);
    process.exit();
  });

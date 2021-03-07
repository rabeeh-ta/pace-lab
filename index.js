require('./db/mongoose');
const express = require('express');

const codeRouter = require('./routes/codeRoutes');

//? setup express
const app = express();
const port = process.env.PORT || 4000;

//? express configurations
app.use(express.json());
app.use(codeRouter);

app.listen(port, () => {
  console.log('Express running on port ' + port);
});

// const test = () => {
//   const code = new Code();
//   console.log(code);
// };

// test();

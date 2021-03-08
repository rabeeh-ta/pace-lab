require('./db/mongoose');
const path = require('path');
const express = require('express');

const codeRouter = require('./routes/codeRoutes');
const frontRouter = require('./routes/frontEnd');

//? setup express
const app = express();
const port = process.env.PORT || 3000;

//? express configurations
app.use(express.json());
app.use(express.static('public'));
app.use(codeRouter);
app.use(frontRouter);

app.listen(port, () => {
  console.log('Express running on port ' + port);
});

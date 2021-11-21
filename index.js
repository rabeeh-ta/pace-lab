require('./db/mongoose');
const path = require('path');
const express = require('express');
const cors = require('cors');
const cookieParser = require('cookie-parser');

const codeRouter = require('./routes/codeRoutes');
const userRouter = require('./routes/userRoutes');
const frontRouter = require('./routes/frontEnd');

//? setup express
const app = express();
const port = process.env.PORT || 3000;

//? express configurations
app.use(cors());
app.use(express.json());
app.use(express.static('public'));
app.use(cookieParser());

//? application logic/backend routes
app.use(codeRouter);
app.use(userRouter);
app.use(frontRouter);

app.listen(port, () => {
  console.log('Express running on port ' + port);
});

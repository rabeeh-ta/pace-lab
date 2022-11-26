require('dotenv').config();
require('./db/mongoose');
const express = require('express');
const cors = require('cors');
const cookieParser = require('cookie-parser');

//? different routes files.
const codeRouter = require('./routes/codeRoutes');
const userRouter = require('./routes/userRoutes');
const downloadsRouter = require('./routes/downloadsRoutes');

//? setup express
const app = express();
const port = process.env.PORT || 3000;

//? redirect http to https
app.use((req, res, next) => {
  if (process.env.NODE_ENV == 'production') {
    if (req.headers['x-forwarded-proto'] != 'https')
      // the statement for performing our redirection
      return res.redirect('https://' + req.headers.host + req.url);
    else return next();
  } else return next();
});

//? express configurations
app.use(cors());
app.use(express.json());
app.use(express.static('downloads'));
app.use(cookieParser());

//? application logic/backend routes
app.use(codeRouter);
app.use(userRouter);
app.use(downloadsRouter);

app.listen(port, () => {
  console.log('Express running on port ' + port);
});

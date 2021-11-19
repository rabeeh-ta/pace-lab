require('dotenv').config();
const jwt = require('jsonwebtoken');

//? middle ware function where it will check if the JWT that the user has send is valid or not.
var authenticateJWT = function (req, res, next) {
  const authHeader = req.headers['authorization'];
  const token = authHeader && authHeader.split(' ')[1]; //if there is a jwt token passed then return the token else UNDEFINED, the split(' ')[1] will get the token part from the string passed in the Header "Bearer KEY"

  if (token == null) return res.sendStatus(401); // if no token is passed then no access granted login

  jwt.verify(token, process.env.ACCESS_TOKEN_SECRET, (err, user) => {
    if (err) return res.sendStatus(403); // you have a token but it is not valid
    req.user = user; // user => the decrypted value which was inside the JWT
    next();
  });
};

module.exports = { authenticateJWT };

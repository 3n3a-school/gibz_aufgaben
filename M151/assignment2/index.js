const express = require('express');
let expressLayouts = require('express-ejs-layouts');
const app = express();
const session = require('express-session');
const routes = require('./routes/router');
require('dotenv').config();

const PORT = process.env.PORT || 3000;

app.use(express.static('public'))

app.use(expressLayouts);
app.set('layout', './layout/main');
app.set('view engine', 'ejs');

app.use(
  session({
    secret: process.env.SECRET,
    resave: false,
    saveUninitialized: true,
  })
);

app.use(express.urlencoded({ extended: false }));

app.use(routes);

const server = app.listen(PORT, () => {
  console.log(`Listening on port ${PORT}`);
});

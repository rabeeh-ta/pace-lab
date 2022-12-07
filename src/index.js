import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';

import Sidebar from './Sidebar';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <div className="">
      <Sidebar />
    </div>
  </React.StrictMode>
);

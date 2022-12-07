/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ['./src/**/*.{js,jsx,ts,tsx}'],
  theme: {
    extend: {
      colors: {
        'primary-color': '#202225',
        'secondary-color': '#2F3136',
        'normal-color': '#36393F',
      },
    },
  },
  plugins: [],
};

window.addEventListener('load', function () {
  loaded();
});

function loaded() {
  var homePage = new Vue({
    el: '#homePage',
    data: {
      message: 'Hello Vue!',
      codes: [],
    },
    created() {
      fetch('https://code-share-rbh.herokuapp.com/codes', {
        method: 'GET',
        headers: { 'Content-type': 'application/json;charset=UTF-8' },
      })
        .then((response) => response.json())
        .then((json) => {
          console.log(json);
          this.codes = json;
        })
        .catch((err) => console.log(err));
    },
  });
}

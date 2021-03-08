window.addEventListener('load', function () {
  loaded();
});

function loaded() {
  var homePage = new Vue({
    el: '#homePage',
    data: {
      message: 'Hello Vue!',
    },
    created() {
      axios
        .get('https://code-share-rbh.herokuapp.com/codes')
        .then((response) => {
          const users = response.data.data;
          console.log(`GET list users`, users);
        })
        .catch((error) => console.error(error));
    },
  });
}

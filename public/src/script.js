window.addEventListener('load', function () {
  loaded();
});

function loaded() {
  var homePage = new Vue({
    el: '#homePage',
    data: {
      message: 'Hello Vue!',
      user: [],
    },
    created() {
      axios
        .get('https://code-share-rbh.herokuapp.com/codes')
        .then((response) => {
          this.users = response.data.data;
          console.log(`GET list users`, this.users);
        })
        .catch((error) => console.error(error));
    },
  });
}

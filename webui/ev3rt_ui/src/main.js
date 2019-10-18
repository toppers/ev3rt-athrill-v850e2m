import Vue from 'vue'
import App from './App.vue'
import ToggleButton from 'vue-js-toggle-button'
import { ros_connect } from './athrill_roslib'

Vue.use(ToggleButton)
Vue.config.productionTip = false
ros_connect();

new Vue({
  render: h => h(App),
}).$mount('#app')

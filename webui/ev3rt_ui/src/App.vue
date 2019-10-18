<template>
  <div id="app">
    <table>
      <tr>
        <td></td>
        <td>
          <PushButton msg='U'/>
        </td>
        <td></td>
      </tr>
      <tr>
        <td>
          <PushButton msg='L'/>
        </td>
        <td>
          <PushButton msg='E'/>
        </td>
        <td>
          <PushButton msg='R'/>
        </td>
      </tr>
      <tr>
        <td></td>
        <td>
          <PushButton msg='D'/>
        </td>
        <td></td>
      </tr>
      <tr>
      </tr>
    </table>

    <table>
      <tr>
        <td>
          <LedLight msg='LED1' on_color='red' off_color='purple'/>
        </td>
        <td>
          <LedLight msg='LED2' on_color='lime' off_color='green'/>
        </td>
      </tr>
    </table>

  </div>
</template>

<script>
import PushButton from './components/PushButton.vue'
import LedLight from './components/LedLight.vue'

export default {
  name: 'app',
  components: {
    PushButton,
    LedLight
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>

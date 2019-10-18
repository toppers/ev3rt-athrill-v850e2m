<template>
    <div id="pbtn">
        <table>
        <tr>
            <td>
                <button class="button" v-on:mousedown="downHandler" v-on:mouseup="upHandler">{{msg}}</button>
            </td>
        </tr>
        </table>
    </div>
</template>

<script>
import {ros_advertise, ros_publish } from '../athrill_roslib.js'

export default {
    el: '#pbtn',
    name:'PushButton',
    props: {
        msg: String
    },
   data: function() {
       return {
            count: '',
            ros_pub: Object
       }
   },
    methods: {
        downHandler: function() {
            this.count--;
            ros_publish(this.ros_pub, "bit_on");
        },
        upHandler: function() {
            this.count++;
            ros_publish(this.ros_pub, "bit_off");
        }
    },
    created() {
        this.ros_pub = ros_advertise('push_btn_' + this.msg);
    }
 }

</script>

<style scoped>
.button {
  filter: brightness(150%);
  position: relative;
            height: 40px;
            width: 40px;
  background-color: rgb(165, 194, 91);
  border-radius: 4px;
  color: #000000;
  line-height: 52px;
  -webkit-transition: none;
  transition: none;
  box-shadow: 0 3px 0 rgba(0, 0, 0, .3);
  text-shadow: 0 1px 1px rgba(0, 0, 0, .3);
}
.button:hover {
  filter: brightness(140%);
  background-color: rgb(165, 194, 91);
  box-shadow: 0 3px 0 rgba(0, 0, 0, .3);
}
.button:active {
  filter: brightness(130%);
  top: 3px;
  box-shadow: none;
}
</style>
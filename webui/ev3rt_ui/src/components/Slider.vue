<template>
    <div id=slider>
        <table>
            <tr>
                <td>
                    <h3>{{msg}}</h3>
                </td>
                <td>
                    <input type="range" v-on:mouseup="eventHandler" v-model="my_value" v-bind:min="min" v-bind:max="max" v-bind:step="step">
                </td>
                <td>
                    <output>{{my_value}}</output>
                </td>
            </tr>
        </table>
    </div>
</template>

<script>
import {ros_advertise, ros_publish } from '../athrill_roslib.js'

export default {
    el: '#slider',
    name:'Slider',
    props: {
        msg: String,
        min: String,
        max: String,
        step: String,
        value: String,
    },
    data: function() {
        return {
            my_value:String,
            ros_pub: Object
        }
    },
    methods: {
        eventHandler: function() {
            ros_publish(this.ros_pub, this.my_value);
        },
    },
    created() {
        this.my_value = this.value;
        this.ros_pub = ros_advertise('sensor_' + this.msg);
    }
}
</script>

<style scoped>
</style>
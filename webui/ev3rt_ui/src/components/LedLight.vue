<template>
    <div id="led">
        <table>
        <tr>
            <td>
                <h3>{{msg}}</h3>
            </td>
            <td class="led_background">
                <div id="app_led" class="led" 
                    v-bind:style={color:ledLightStrength}>●</div>
            </td>
        </tr>
        </table>
    </div>
</template>

<script>
import { ros_subscribe } from '../athrill_roslib.js'

export default {
    el: '#led',
    name:'LedLight',
    props: {
        msg: String,
        on_color: String,
        off_color: String
    },
    data: function() {
        return {
            isActive: true,
            ledLightStrength: this.on_color,
        }
    },
    methods: {
        overHandler: function() {
            this.isActive = true;
            this.ledLightStrength = this.on_color;
        },
        outHandler: function() {
            this.isActive = false;
            this.ledLightStrength = this.off_color;
        },
        eventHandler: function(message) {
            if (message == 'bit_on') {
                this.overHandler();
            }
            else {
                this.outHandler();
            }
        }
    },
    created() {
        ros_subscribe('led_' + this.msg, this.eventHandler);
    }
}
</script>

<style scoped>
.led {
  font-size: 5em;
  filter: blur(4px);
}

.led_background {
  background: #000000;
}

</style>
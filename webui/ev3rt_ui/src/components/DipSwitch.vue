<template>
    <div class="dsw">
        <table>
        <tr>
            <td>
                <h3>{{msg}}</h3>
            </td>
            <td>
                <toggle-button @change="onChangeEventHandler" value="false"
                                color="#82C7EB"
                                height="30"
                                width="60"
                                :sync="true"
                                :labels="true"></toggle-button>   
            </td>
        </tr>
        </table>
    </div>
</template>

<script>
export default {
    el: '#dsw',
    name:'DipSwitch',
    props: {
        msg: String
    },
   data: function() {
       return {
            myDataVariable: ''
       }
   },
   methods: {
    onChangeEventHandler: function(){
    }
   }
 }

</script>

<style scoped>
</style>
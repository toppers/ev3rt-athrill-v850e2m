const ROSLIB = require("roslib");
var ros;

export function ros_connect() {
  ros =  new ROSLIB.Ros({
    url: 'ws://localhost:9090'
  });
  ros.on('connection', () => {
    alert('Connected to websocket server');
  });

  ros.on('error', error =>{
    alert('Error connecting to websocket server: ', error);
  });

  ros.on('close', () => {
    alert("Connection to websocket server was closed");
  });
}

export function ros_advertise(topic_name) {
  const pub = new ROSLIB.Topic({
    ros : ros,
    name : topic_name,
    messageType : 'std_msgs/String'
  });
  return pub;
}

export function ros_publish(pub, msg) {
  var snd_msg = new ROSLIB.Message({
    data : msg
  });
  pub.publish(snd_msg);
}

export function ros_subscribe(topic_name, func) {
  const listener = new ROSLIB.Topic({
    ros : ros,
    name : topic_name,
    messageType : 'std_msgs/String'
   });
   listener.subscribe(message => func(message.data));
}
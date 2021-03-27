{
        "core_ipaddr": "{{RESOLVE_IPADDR}}",
        "core_portno": 50051,
        "asset_timeout": 3,
		"SymTimeMeasureFilePath": "{{SYMTIME_MEASURE_FILEPATH}}",
        "inside_assets": [
	       	{
	        	"name": "RoboModel",
	        	"pdu_writer_names":  [
	        		"Ev3SensorPdu",
		        ],
	        	"pdu_reader_names":  [
	        		"Ev3ActuatorPdu",
		        ],
        	}
        ],
        "outside_assets":  [
	       	{
	        	"name": "Athrill",
	        	"class_name": "Ev3MiconAssetController",
        	}
        ],
        "pdu_writers":  [
	       	{
	        	"name": "Ev3SensorPdu",
	        	"class_name": "Ev3PduWriter",
        	}
        ],
        "pdu_readers":  [
	       	{
	        	"name": "Ev3ActuatorPdu",
	        	"class_name": "Ev3PduReader",
        	}
        ],
        "udp_methods":  [
	       	{
	        	"method_name": "UdpMethod1",
	        	"ipaddr": "{{IFCONFIG_IPADDR}}",
	        	"portno": 54002,
	        	"iosize": 1024,
	        	"is_read": false,
        	},
	       	{
	        	"method_name": "UdpMethod2",
	        	"ipaddr": "{{RESOLVE_IPADDR}}",
	        	"portno": 54001,
	        	"iosize": 1024,
	        	"is_read": true,
        	}
        ],
        "mmap_methods": null,
        "reader_connectors":  [
	       	{
	        	"name": "reader_connector1",
	        	"pdu_name": "Ev3ActuatorPdu",
	        	"method_name": "UdpMethod2",
        	}
        ],
        "writer_connectors":  [
	       	{
	        	"name": "writer_connector1",
	        	"pdu_name": "Ev3SensorPdu",
	        	"method_name": "UdpMethod1",
        	}
        ],
        "pdu_channel_connectors":  [
	       	{
	        	"outside_asset_name": "Athrill",
	        	"reader_connector_name": "reader_connector1",
	        	"writer_connector_name": "writer_connector1",
        	}
        ],
}

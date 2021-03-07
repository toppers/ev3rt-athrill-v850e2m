{
	"AthrillPath": null,
	"TerminalPath": null,
	"CoreIpAddr":"{{RESOLVE_IPADDR}}",
	"CorePort":50051,
	"SymTimeMeasureFilePath": "{{SYMTIME_MEASURE_FILEPATH}}",
	"robots": [
		{
			"RobotName": "RoboModel",
			"WorkspacePathWin": null,
			"WorkspacePathUnix": null,
			"ApplicationName": "{{APL}}",
			"BinaryName": "asp",
			"Udp":
			{
				"AthrillIpAddr":"{{IFCONFIG_IPADDR}}",
				"AthrillPort":54002,
				"UnityPort":54001
			}
		}
	]
}

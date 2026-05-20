#if !defined(WIFI_DEFINED)
	#define WIFI_DEFINED
	
	// TODO: dit bestand volledig aanpassen aan je eigen noden...
	
	// WiFi-instellingen.	
	#define WIFI_SSID 			"devbit"
	#define WIFI_PWD 				"Dr@@dloos!"
	
	// De hosts definiëren.
	// Let op: de host name mag maximum 64 bytes lang zijn, anders 'ERROR' bij CIPSTART!
	#define HTTP_HOST 						""
	#define HTTPS_HOST 						"labo-h5-6iot-default-rtdb.europe-west1.firebasedatabase.app"  // Deze database link kan je opzoeken in je Firebase console.
	
	// URL's definiëren.
	#define HTTP_URL_GET 			"/iot/esp32c3/index.php"
	#define HTTP_URL_POST			"/iot/esp32c3/index.php"	
	#define HTTPS_URL_GET 		"/advalue.json"							// Wil je in één specifieke waarde lezen, zet dan '/advalue.json'.
	#define HTTPS_URL_PATCH 	"/Knoppen"										// Wil je in de 'root' schrijven, zet dan '/.json'.
	
	// API key voor HTTP.
	#define HTTP_APIKEY 		""
	
	// API key voor HTTPS.
	// Om zonder 'authenticatie objecten' te kunnen werken, moet een unieke sleutel mee verzonden worden.
	// Je kan het 'database secret' opvragen via de Firebase console. Zie: Project settings -> Service Accounts -> Database secrets.
	#define HTTPS_DATABASE_SECRET	"uD26yYf4ybS6RlLkMJU8Yo6F4j3gkqfsknRCG8zv"	
	
	// MQTT defines.	
	#define MQTT_SUB_TOPIC 				""
	#define MQTT_PUB_TOPIC 				""
	#define MQTT_BROKER_ADDRESS 	""
	#define MQTT_PORT 						0
	#define MQTT_USER 						""
	#define MQTT_PWD 							""
	#define MQTT_CLIENT_ID 				"ESP32C3_7-22"
#endif

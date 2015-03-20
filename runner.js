chrome.browserAction.onClicked.addListener(function(tab){

	var bp = chrome.extension.getBackgroundPage();

	var port = chrome.runtime.connectNative('com.giantsource.runner');

	console.log("port: ", port);

	port.onMessage.addListener(function(msg){
		console.log("MSG: ", msg);
		debugger;
	});

	port.onDisconnect.addListener(function(){
		console.log("DISCONNECTED");
	});

	port.postMessage({text: "hello world!" });
});
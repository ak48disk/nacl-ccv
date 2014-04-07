// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var stream;

function success(s) {
  stream = s;
  common.naclModule.postMessage({track: stream.getVideoTracks()[0]});
}

function failure(e) {
  common.logMessage("Error: " + e);
}

function moduleDidLoad() {
  navigator.webkitGetUserMedia({'video': true}, success, failure);
}

function handleMessage(message_event) {
	var msg = message_event.data;
	var context = document.getElementById("canvas").getContext("2d");
	if (msg.faces.length != 0) {
		console.log(msg.faces);
		context.clearRect(0,0,640,480);
		for(var i=0;i<msg.faces.length;++i) {
			var face = msg.faces[i];
			context.beginPath();
			context.moveTo(face.x,face.y);
			context.lineTo(face.x,face.y+face.height);
			context.lineTo(face.x+face.width,face.y+face.height);
			context.lineTo(face.x+face.width,face.y);
			context.lineTo(face.x,face.y);
			context.stroke();
		}
	}
}

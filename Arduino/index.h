const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
.card {
  max-width: 400px;
  min-height: 250px;
  background: #02b875;
  padding: 30px;
  box-sizing: border-box;
  color: #FFF;
  margin:20px;
  box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
.button {
  background: blue;
  padding: 10px;
  box-sizing: border-box;
  color: #FFF;
  margin:20px;
}

</style>
<body>

<div class="card">
  <h1>Smart Motor</h1><br>
  <h2>Water Flow Rate:<span id="flowSensorValue">0</span> l/hour</h2><br>
  <button id="relayButton" class="button"><span id="RelayState"></span></button>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 1 Second interval
  getFlowSensorData();
  getRelayState();
}, 1000); //1000mSeconds update rate

function getFlowSensorData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("flowSensorValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readFlowSensor", true);
  xhttp.send();
}

function getRelayState() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("RelayState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "getRelayState", true);
  xhttp.send();
}

document.getElementById("relayButton").onclick = function handleRelay() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("RelayState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "handleRelay", true);
  xhttp.send();
}

</script>
</body>
</html>
)=====";

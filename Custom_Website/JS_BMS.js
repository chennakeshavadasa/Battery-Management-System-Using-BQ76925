// Function to update sensor values
function updateSensorValues(sensor1, sensor2, sensor3, uptime) {
    document.getElementById('current').textContent = sensor1;
    document.getElementById('voltage').textContent = sensor2;
    document.getElementById('temperature').textContent = sensor3;
    document.getElementById('uptime').textContent = uptime;
    
    // Check if any value exceeds safe limits
    if (sensor1 > safeCurrent || sensor2 > safeVoltage || sensor3 > safeTemperature) {
        alert("Alert: Voltage, Current, or Temperature exceeds safe limits!");
    }
}

// Function to update chart data
function updateChart(data) {
    myChart.data.labels.push(new Date().toLocaleTimeString());
    myChart.data.datasets[0].data.push(data);
    myChart.update();
}

// Create a chart context
var ctx = document.getElementById('chart').getContext('2d');

// Create the chart
var myChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [], // x-axis labels (time)
        datasets: [{
            label: 'Sensor Value',
            data: [], // y-axis data
            borderColor: 'rgba(75, 192, 192, 1)',
            borderWidth: 1,
            fill: false
        }]
    },
    options: {
        scales: {
            x: {
                type: 'time',
                time: {
                    unit: 'second'
                }
            },
            y: {
                beginAtZero: true
            }
        }
    }
});

// Define safe values
var safeCurrent = 2.5; // Example safe current value (adjust as needed)
var safeVoltage = 240;  // Example safe voltage value (adjust as needed)
var safeTemperature = 30; // Example safe temperature value (adjust as needed)

// Update sensor values (replace with actual data)
var sensor1Value = 10.5;
var sensor2Value = 220;
var sensor3Value = 25;
var uptimeValue = 3600;

updateSensorValues(sensor1Value, sensor2Value, sensor3Value, uptimeValue);

// Update chart with example data
updateChart(sensor1Value); // You can call this function whenever you have new sensor data

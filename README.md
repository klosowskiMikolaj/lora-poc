# lora-poc
Ordered by NewLink Kamil Klepacki, made public due to missing final payment.
Zamówione przez NewLink Kamil Klepacki, repozytorium upubliczone z powodu braku końcowej płatności.


## gateway
First do the basic setup on http://192.168.88.1/webfig to set the wifi name and password. Then update the device via system -> packages -> check for updates -> Download & Upgrade,  downloads will start, and router will reboot. After the reboot, your router will be running the latest RouterOS version. You can then click the Upgrade button again, to confirm that your router is running the latest RouterOS.

### lora setup

https://www.thethingsindustries.com/docs/gateways/models/mikrotik-knot/

When device was updated it automaticcaly added needed new TTN servers, skip adding new server and choose TTNv3 eu server. 
Open gateway-0 and set antena gain to 20.


## TTN

Copy gateway ID and use it in gateway setup here
https://www.thethingsindustries.com/docs/gateways/concepts/adding-gateways/

You can add multiple gateways under one TTN account

Then create application
https://www.thethingsnetwork.org/docs/applications/add/

Setup mqtt for sending data to the influx via telegraf in your created app
https://www.thethingsindustries.com/docs/integrations/mqtt/
and copy the credentials to the telegraf conf file located in server dir



## server
No need to recreate the server

create VPC and EC2 instance
https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/EC2_GetStarted.html

AWS server ssh using EC2 Instance Connect and run following commands:

`wget https://dl.influxdata.com/influxdb/releases/influxdb2-2.7.0.x86_64.rpm`

`sudo yum localinstall influxdb2-2.7.0.x86_64.rpm`

`sudo service influxdb start`

`wget https://dl.influxdata.com/influxdb/releases/influxdb2-client-2.7.3-linux-amd64.tar.gz`

`tar xvzf influxdb2-client-2.7.3-linux-amd64.tar.gz`

`sudo cp influx /usr/local/bin/`

`influx setup --username kamil.klepacki --password Komputer12345! --org lora --bucket sensor --force`

`influx auth create --org lora --all-access`
copy token to telegraf config file


`influx bucket create -n thing_network_stats -o lora -r 104w`


`sudo openssl req -x509 -nodes -newkey rsa:2048 -keyout /etc/ssl/influxdb-selfsigned.key -out /etc/ssl/influxdb-selfsigned.crt -days 365`

`sudo chmod 644 /etc/ssl/influxdb-selfsigned.crt`

`sudo chmod 644 /etc/ssl/influxdb-selfsigned.key`

Ad to influx config.toml file following lines:

tls-cert = "/etc/ssl/influxdb-selfsigned.crt"
tls-key = "/etc/ssl/influxdb-selfsigned.key"


(this is single command copy it from cat to EOF in line 44)
```cat <<EOF | sudo tee /etc/yum.repos.d/influxdb.repo
[influxdb]
name = InfluxData Repository - Stable
baseurl = https://repos.influxdata.com/stable/\$basearch/main
enabled = 1
gpgcheck = 1
gpgkey = https://repos.influxdata.com/influxdata-archive_compat.key
EOF
```

`sudo yum install telegraf`

update connection settings to TTN and INFLUX in the telegraf conf file then upload it to /etc/telegraf/telegraf.conf

`sudo service telegraf start`


Now you can login via public url from EC2 console:

https://ec2-3-253-9-195.eu-west-1.compute.amazonaws.com:8086/orgs/dacb5a4ce3a2a6d0
creds:
kamil.klepacki
Komputer12345!

if the data is not comming to the server please restart the telegraf service via 
`sudo service telegraf start`


## influxDB setup

settings-> variables-> create new -> name device, type query, script:

```
import "influxdata/influxdb/schema"
schema.tagValues(bucket: "sensor", tag: "topic")
```
submit

dashboard -> create -> import dashboard -> drag and drop sensordata.jason file 


## device

https://wiki.seeedstudio.com/LoRa_E5_mini/

reads 
 * adc for 
    * battery level 
    * capacitive moisture level sensor
    * 3x generic moisture level sensor
* digital pin for temperature

Then sends it every 30s to the LoRaWan

Identity se header file is used for the updating secrets for programming new devices

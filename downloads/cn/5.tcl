    # This script is created by NSG2 beta1
# <http://wushoupong.googlepages.com/nsg>

#===================================
#     Simulation parameters setup
#===================================
set val(stop)   50.0                         ;# time of simulation end
set opt(title) zero;
set opt(stop) 50;
set opt(ecn) 0;

#topology
set opt(type) gsm ;
set opt(secondDelay) 55;

#AQM parameters
set opt(minth) 30;
set opt(maxth0 0;
set opt(adaptive) 1;

#traffic generation
set opt(flows) 0;
set opt(window) 30;
set opt(web) 2;

#default downlink bandwith in bps
set bwDL(gsm) 9600

#default uplink bandwith in bps
set bwUL(gsm) 9600

#default downlink propogation delay in sec
set propDL(gsm) .500

#default uplink propogation delay in sec 
set propUL(gsm) .500

#default buffer size in packets
set buf(gsm) 10
#end

#===================================
#        Initialization        
#===================================
#Create a ns simulator
set ns [new Simulator]

#Open the NS trace file
set tracefile [open 5nn.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open 5nn.nam w]
$ns namtrace-all $namfile

#===================================
#        Nodes Definition        
#===================================
#Create 5 nodes
set nodes(n0) [$ns node]
set nodes(n1) [$ns node]
set nodes(n2) [$ns node]
set nodes(n3) [$ns node]
set nodes(n4) [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes

proc cell_topo {} {
global ns nodes
$ns duplex-link $nodes(n0) $nodes(n1) 3.0Mb 10ms DropTail

$ns duplex-link $nodes(n1) $nodes(n2) 1.0Mb 10ms RED

$ns duplex-link $nodes(n2) $nodes(n3) 1.0Mb 10ms RED

$ns duplex-link $nodes(n3) $nodes(n4) 3.0Mb 10ms DropTail

puts " Cell Topology"
}

proc set_link_params {t} {
global ns nodes bwUL bwDL propUL propDL buf
$ns bandwidth $nodes(n0) $nodes(n1) $bwDL($t) duplex
$ns bandwidth $nodes(n1) $nodes(n2) $bwUL($t) duplex
$ns bandwidth $nodes(n2) $nodes(n3) $bwDL($t) duplex
$ns bandwidth $nodes(n3) $nodes(n4) $bwUL($t) duplex

$ns delay $nodes(n0) $nodes(n1) $propDL($t) duplex
$ns delay $nodes(n1) $nodes(n2) $propDL($t) duplex
$ns delay $nodes(n2) $nodes(n3) $propDL($t) duplex
$ns delay $nodes(n3) $nodes(n4) $propDL($t) duplex


$ns queue-limit $nodes(n0) $nodes(n1) $buf($t)
$ns queue-limit $nodes(n1) $nodes(n2) $buf($t)
$ns queue-limit $nodes(n2) $nodes(n3) $buf($t)
$ns queue-limit $nodes(n3) $nodes(n4) $buf($t)
}

#create topology
switch $opt(type) {
gsm -
gprs -
umts {cell_topo}
}
set_link_params $opt(type)
$ns insert-delayer $nodes(n0) $nodes(n1) [new Delayer]
$ns insert-delayer $nodes(n1) $nodes(n2) [new Delayer]
$ns insert-delayer $nodes(n2) $nodes(n3) [new Delayer]
$ns insert-delayer $nodes(n3) $nodes(n4) [new Delayer]


#===================================
#        Agents Definition        
#===================================
#Setup a TCP connection
set tcp0 [new Agent/TCP]
$ns attach-agent $nodes(n0) $tcp0
set sink2 [new Agent/TCPSink/Sack1]
$ns attach-agent $nodes(n2) $sink2
$ns connect $tcp0 $sink2
$tcp0 set packetSize_ 1500

#Setup a TCP connection
set tcp1 [new Agent/TCP]
$ns attach-agent $nodes(n0) $tcp1
set sink3 [new Agent/TCPSink/Sack1]
$ns attach-agent $nodes(n2) $sink3
$ns connect $tcp1 $sink3
$tcp1 set packetSize_ 1500


#===================================
#        Applications Definition        
#===================================
#Setup a FTP Application over TCP connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 1.0 "$ftp0 start"
$ns at 35.0 "$ftp0 stop"

#Setup a FTP Application over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ns at 1.0 "$ftp1 start"
$ns at 45.0 "$ftp1 stop"


#===================================
#        Termination        
#===================================
#Define a 'finish' procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run

                  

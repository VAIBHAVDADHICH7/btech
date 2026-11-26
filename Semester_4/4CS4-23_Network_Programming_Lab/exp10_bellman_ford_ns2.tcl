# Exp 10: Simulate Bellman-Ford (Distance Vector) Routing in NS2
set ns [new Simulator]
$ns rtproto DV

set nf [open bellman_ford.nam w]
$ns namtrace-all $nf

for {set i 0} {$i < 5} {incr i} {
    set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(1) 1Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 1Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 1Mb 10ms DropTail
$ns duplex-link $n(3) $n(4) 1Mb 10ms DropTail
$ns duplex-link $n(4) $n(0) 1Mb 10ms DropTail

set udp0 [new Agent/UDP]
$ns attach-agent $n(0) $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n(3) $null0
$ns connect $udp0 $null0

$ns at 0.5 "$cbr0 start"
$ns rtmodel-at 1.5 down $n(1) $n(2)
$ns rtmodel-at 2.5 up $n(1) $n(2)
$ns at 4.0 "$cbr0 stop"
$ns at 4.5 "finish"

proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exit 0
}
$ns run

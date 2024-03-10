Postmortem: Ethiopian Airlines Crew Per Diem Payment Delay (March 9th, 2024)
Issue Summary

Duration: Crew member per diem payments were delayed for approximately 6 hours, starting at 2:00 AM EAT on March 9th, 2024, and resolving by 8:00 AM EAT.

Impact: Crew members who rely on per diem payments for out-of-pocket expenses during layovers experienced a delay in receiving their funds. This could have caused inconvenience and potentially financial strain.

Root Cause: The delay was caused by a resource issue on the Ethiopian Airlines host system combined with network connectivity problems.

Timeline

2:00 AM EAT: Automated per diem payment process encountered an error.
2:15 AM EAT: Monitoring alerts indicated a failure within the crew per diem payment system.
2:15 AM EAT - 4:00 AM EAT: The IT team investigated the issue. Initial focus was on the payment processing application itself, assuming a software bug.
4:00 AM EAT: Further investigation revealed insufficient system resources on the host server coinciding with a network connectivity issue.
4:00 AM EAT - 6:00 AM EAT: The IT team allocated additional resources to the host server and worked with network engineers to diagnose and resolve the network connectivity problem.
6:00 AM EAT - 8:00 AM EAT: With increased server resources and a stable network connection, the per diem payment process resumed and the backlog was cleared.
Root Cause and Resolution

The root cause of the delay was a combination of two factors:

Resource limitations: The host server running the crew per diem payment application encountered insufficient resources to handle the processing load.
Network connectivity issues: Network connectivity problems further hampered communication between the application and external systems needed for payment processing.
The IT team resolved the issue by:

Provisioning additional resources: Allocating more processing power and memory to the host server to ensure smooth operation of the payment application.
Resolving network connectivity problems: Working with network engineers to diagnose and fix the network issue that was affecting communication.
Corrective and Preventative Measures

System resource monitoring: Implement stricter monitoring of system resources on the host server to identify potential bottlenecks before they cause disruptions.
Scalability improvements: Evaluate the crew per diem payment application for scalability improvements to handle increased processing demands. This might involve implementing a distributed architecture.
Network redundancy: Investigate implementing network redundancy measures to minimize the impact of future network connectivity problems.
Automated recovery procedures: Develop automated procedures to detect and attempt to recover from resource or network issues without requiring manual intervention.
Crew communication: Improve communication channels with crew members to provide timely updates during payment processing delays.


Houston, We Have a Problem (With Crew Per Diem Payments) ✈️
Have you ever dreamt of a world where those Ethiopian Airlines per diem payments hit your account like clockwork?  Well, buckle up, because on March 9th, 2024, that dream became a temporary layover... for about 6 hours .

This postmortem isn't your average snoozefest. We'll dissect what caused the delay in those sweet, sweet funds reaching your accounts, and most importantly, how we're making sure it doesn't happen again. (Think of it as pre-flight checks for our payment system).

Why You Should Care (Besides Money)
Let's face it, delayed payments can be a major headache, especially when you're relying on them for those essential layover expenses. We get it, and we take this seriously.  This postmortem is all about transparency and ensuring your trust in our systems.

So, What Went Wrong?
Imagine a server overloaded with tasks, like a buffet overflowing with delicious options (but causing indigestion ).  Combine that with a spotty internet connection, like trying to use Wi-Fi at a crowded airport (you know the struggle).  Those were the culprits behind the delay.

[Insert comical diagram here: Maybe a server overloaded with cash or airline tickets, tangled up with a weak Wi-Fi signal]

How Did We Fix It?
Our IT team, the real-life heroes of this story, acted fast. They were basically the engineers who diagnosed the engine trouble and got you back in the air (virtually, of course). Here's what they did:

Upgraded the Server: Think of it as giving the server more horsepower to handle all those payment transactions.
Patched Up the Network: Just like fixing a faulty wire, they identified and resolved the network issue causing the sluggish connection.
Preventing Future Turbulence
We're not just patching things up here. We're taking proactive measures to ensure smooth sailing for future payments.

Constant Monitoring: We'll be keeping a closer eye on our systems, just like pilots monitoring vital flight instruments.
System Upgrades: We're exploring ways to make the payment system more scalable, think of it as adding extra fuel tanks for longer flights (of data, that is).
Communication is Key: We'll strive for better communication during any future delays, keeping you informed every step of the way.

# examtopics 
select 3 answers from 6 choices -> 2 questions
select 2 answers from 5 choices -> 8~10? questions
select 1 answers from 4 choices -> rest of questions

398+ ,400-950

https://www.examtopics.com/discussions/amazon/view/53233-exam-aws-certified-solutions-architect-professional-topic-1/
390. You set up your first Lambda function and want to set up some Cloudwatch metrics to monitor your function. Which of the following Lambda metrics can
Cloudwatch monitor?
A. Total requests only
B. Status Check Failed, total requests, and error rates
C. Total requests and CPU utilization
D. Total invocations, errors, duration, and throttles
>`D`

https://www.examtopics.com/discussions/amazon/view/6474-exam-aws-certified-solutions-architect-professional-topic-1/
391. How many metrics are supported by CloudWatch for Auto Scaling?
A. 7 metrics and 5 dimension
B. 5 metrics and 1 dimension
C. 1 metric and 5 dimensions
D. 8 metrics and 1 dimension
>`D`

https://www.examtopics.com/discussions/amazon/view/38642-exam-aws-certified-solutions-architect-professional-topic-1/
392. A user has enabled detailed CloudWatch monitoring with the AWS Simple Notification Service. Which of the below mentioned statements helps the user understand detailed monitoring better?
A. SNS cannot provide data every minute
B. SNS will send data every minute after configuration
C. There is no need to enable since SNS provides data every minute
D. AWS CloudWatch does not support monitoring for SNS
>`C`
"Amazon Simple Notification Service (Amazon SNS) now publishes metrics at 1-minute resolution to Amazon CloudWatch, providing granular monitoring for Amazon SNS standard and FIFO topics. Previously, Amazon SNS published metrics to Amazon CloudWatch in 5-minute resolution. "
https://aws.amazon.com/about-aws/whats-new/2021/01/amazon-sns-now-supports-1-minute-cloudwatch-metrics/?nc1=h_ls


https://www.examtopics.com/discussions/amazon/view/12860-exam-aws-certified-solutions-architect-professional-topic-1/
393. An AWS account owner has setup multiple IAM users. One of these IAM users, named John, has CloudWatch access, but no access to EC2 services. John has setup an alarm action which stops EC2 instances when their CPU utilization is below the threshold limit.
When an EC2 instance's CPU Utilization rate drops below the threshold John has set, what will happen and why?
A. CloudWatch will stop the instance when the action is executed
B. Nothing will happen. John cannot set an alarm on EC2 since he does not have the permission.
C. Nothing will happen. John can setup the action, but it will not be executed because he does not have EC2 access through IAM policies.
D. Nothing will happen because it is not possible to stop the instance using the CloudWatch alarm
>`C`
answer is C
"To set up a CloudWatch alarm action that can reboot, stop, or terminate an instance, you must use a service-linked IAM role, AWSServiceRoleForCloudWatchEvents. The AWSServiceRoleForCloudWatchEvents IAM role enables AWS to perform alarm actions on your behalf."
https://docs.aws.amazon.com/AmazonCloudWatch/latest/monitoring/UsingAlarmActions.html

https://www.examtopics.com/discussions/amazon/view/20043-exam-aws-certified-solutions-architect-professional-topic-1/
394. A user has configured an EC2 instance in the US-East-1a zone. The user has enabled detailed monitoring of the instance. The user is trying to get the data from
CloudWatch using a CLI.
Which of the below mentioned CloudWatch endpoint URLs should the user use?
A. monitoring.us-east-1a.amazonaws.com
B. cloudwatch.us-east-1a.amazonaws.com
C. monitoring.us-east-1.amazonaws.com
D. monitoring.us-east-1-a.amazonaws.com
>`C`
Answer is C:
https://docs.aws.amazon.com/general/latest/gr/cw_region.html

https://www.examtopics.com/discussions/amazon/view/12861-exam-aws-certified-solutions-architect-professional-topic-1/
395. Which of the following is not included in the metrics sent from Billing to Amazon CloudWatch?
A. Recurring fees for AWS products and services
B. Total AWS charges
C. One-time charges and refunds
D. Usage charges for AWS products and services
Ans.: C
(Included) A. Recurring fees for AWS products and services
“It includes usage charges for things like Amazon EC2 instance-hours and recurring fees for things like AWS Premium Support. “

(Included) B. Total AWS charges
“Estimated Charges: Total”

(Not included) C. One-time charges and refunds
(Included) D. Usage charges for AWS products and services
“Estimated Charges: By Service”

https://aws.amazon.com/ko/blogs/aws/monitor-estimated-costs-using-amazon-cloudwatch-billing-metrics-and-alarms/

https://www.examtopics.com/discussions/amazon/view/10887-exam-aws-certified-solutions-architect-professional-topic-1/
396. After your Lambda function has been running for some time, you need to look at some metrics to ascertain how your function is performing and decide to use the
AWS CLI to do this.
Which of the following commands must be used to access these metrics using the AWS CLI?
A. mon-list-metrics and mon-get-stats
B. list-metrics and get-metric-statistics
C. ListMetrics and GetMetricStatistics
D. list-metrics and mon-get-stats
>B,
https://docs.aws.amazon.com/cli/latest/reference/cloudwatch/get-metric-statistics.html


https://www.examtopics.com/discussions/amazon/view/41792-exam-aws-certified-solutions-architect-professional-topic-1/
397. In Amazon CloudWatch, you can publish your own metrics with the put-metric-data command. When you create a new metric using the put-metric-data command, it can take up to two minutes before you can retrieve statistics on the new metric using the get-metric-statistics command.
How long does it take before the new metric appears in the list of metrics retrieved using the list- metrics command?
A. After 2 minutes
B. Up to 15 minutes
C. More than an hour
D. Within a minute
>B
"After you create a metric, allow up to 15 minutes before the metric appears."
https://awscli.amazonaws.com/v2/documentation/api/latest/reference/cloudwatch/list-metrics.html


https://www.examtopics.com/discussions/amazon/view/4942-exam-aws-certified-solutions-architect-professional-topic-1/
398. A company runs a legacy system on a single m4.2xlarge Amazon EC2 instance with Amazon EBS storage. The EC2 instance runs both the web server and a self- managed Oracle database. A snapshot is made of the EBS volume every 12 hours, and an AMI was created from the fully configured EC2 instance.
A recent event that terminated the EC2 instance led to several hours of downtime. The application was successfully launched from the AMI, but the age of the
EBS snapshot and the repair of the database resulted in the loss of 8 hours of data. The system was also down for 4 hours while the Systems Operators manually performed these processes.
What architectural changes will minimize downtime and reduce the chance of lost data?
A. Create an Amazon CloudWatch alarm to automatically recover the instance. Create a script that will check and repair the database upon reboot. Subscribe the Operations team to the Amazon SNS message generated by the CloudWatch alarm.
B. Run the application on m4.xlarge EC2 instances behind an Elastic Load Balancer/Application Load Balancer. Run the EC2 instances in an Auto Scaling group across multiple Availability Zones with a minimum instance count of two. Migrate the database to an Amazon RDS Oracle Multi-AZ DB instance.
C. Run the application on m4.2xlarge EC2 instances behind an Elastic Load Balancer/Application Load Balancer. Run the EC2 instances in an Auto Scaling group across multiple Availability Zones with a minimum instance count of one. Migrate the database to an Amazon RDS Oracle Multi-AZ DB instance.
D. Increase the web server instance count to two m4.xlarge instances and use Amazon Route 53 round-robin load balancing to spread the load. Enable Route 53 health checks on the web servers. Migrate the database to an Amazon RDS Oracle Multi-AZ DB instance.
>B is correct.
A: Does not address a loss of data since the last backup.
B: Ensures that there are at least two EC instances, each of which is in a different AZ. It also ensures that the database spans multiple AZs. Hence this meets all the criteria.
C: Having auto scaling set to a minimum instance count of one means that if there is just one instance and there is a problem, that instance will need to be restarted, meaning there would an outage during that restart time. As such, B is a better answer.
D: Does not indicate that the two EC2 instances will be in different availability zones. If they are in the same AZ, that entire zone could theoretically have an outage. Given that, I would select B instead of D. Apart from that consideration D does the trick.

https://www.examtopics.com/discussions/amazon/view/5956-exam-aws-certified-solutions-architect-professional-topic-1/
399. A Solutions Architect is working with a company that operates a standard three-tier web application in AWS. The web and application tiers run on Amazon EC2 and the database tier runs on Amazon RDS. The company is redesigning the web and application tiers to use Amazon API Gateway and AWS Lambda, and the company intends to deploy the new application within 6 months. The IT Manager has asked the Solutions Architect to reduce costs in the interim.
Which solution will be MOST cost effective while maintaining reliability?
A. Use Spot Instances for the web tier, On-Demand Instances for the application tier, and Reserved Instances for the database tier.
B. Use On-Demand Instances for the web and application tiers, and Reserved Instances for the database tier.
C. Use Spot Instances for the web and application tiers, and Reserved Instances for the database tier.
D. Use Reserved Instances for the web, application, and database tiers.
>B
D cannot be the correct answer, with RI you can save more than 50% only for 3-year term.
With 1-year term saving is always less than 50%, so does not make sense to buy RI for pieces that you are going to remove in 6 months

https://www.examtopics.com/discussions/amazon/view/5953-exam-aws-certified-solutions-architect-professional-topic-1/
400. A company uses Amazon S3 to store documents that may only be accessible to an Amazon EC2 instance in a certain virtual private cloud (VPC). The company fears that a malicious insider with access to this instance could also set up an EC2 instance in another VPC to access these documents.
Which of the following solutions will provide the required protection?
A. Use an S3 VPC endpoint and an S3 bucket policy to limit access to this VPC endpoint.
B. Use EC2 instance profiles and an S3 bucket policy to limit access to the role attached to the instance profile.
C. Use S3 client-side encryption and store the key in the instance metadata.
D. Use S3 server-side encryption and protect the key with an encryption context.
>A true

https://docs.aws.amazon.com/vpc/latest/userguide/vpce-gateway.html

Endpoint connections cannot be extended out of a VPC. Resources on the other side of a VPN connection, VPC peering connection, AWS Direct Connect connection, or ClassicLink connection in your VPC cannot use the endpoint to communicate with resources in the endpoint service.

https://www.examtopics.com/discussions/amazon/view/5341-exam-aws-certified-solutions-architect-professional-topic-1/
436. A large company experienced a drastic increase in its monthly AWS spend. This is after Developers accidentally launched Amazon EC2 instances in unexpected regions. The company has established practices around least privileges for Developers and controls access to on-premises resources using Active Directory groups. The company now want to control costs by restricting the level of access that Developers have to the AWS Management Console without impacting their productivity. The company would also like to allow Developers to launch Amazon EC2 in only one region, without limiting access to other services in any region.
How can this company achieve these new security requirements while minimizing the administrative burden on the Operations team?
A. Set up SAML-based authentication tied to an IAM role that has an AdministrativeAccess managed policy attached to it. Attach a customer managed policy that denies access to Amazon EC2 in each region except for the one required.
B. Create an IAM user for each Developer and add them to the developer IAM group that has the PowerUserAccess managed policy attached to it. Attach a customer managed policy that allows the Developers access to Amazon EC2 only in the required region.
C. Set up SAML-based authentication tied to an IAM role that has a PowerUserAccess managed policy and a customer managed policy that deny all the Developers access to any AWS services except AWS Service Catalog. Within AWS Service Catalog, create a product containing only the EC2 resources in the approved region.
D. Set up SAML-based authentication tied to an IAM role that has the PowerUserAccess managed policy attached to it. Attach a customer managed policy that denies access to Amazon EC2 in each region except for the one required.



https://www.examtopics.com/discussions/amazon/view/5024-exam-aws-certified-solutions-architect-professional-topic-1/
501. A group of Amazon EC2 instances have been configured as a high performance computing (HPC) cluster. The instances are running in a placement group, and are able to communicate with each other at network speeds of up to 20 Gbps.
The cluster needs to communicate with a control EC2 instance outside of the placement group. The control instance has the same instance type and AMI as the other instances, and is configured with a public IP address.
How can the Solutions Architect improve the network speeds between the control instance and the instances in the placement group?
A. Terminate the control instance and relaunch it in the placement group.
B. Ensure that the instances are communicating using their private IP addresses.
C. Ensure that the control instance is using an Elastic Network Adapter.
D. Move the control instance inside the placement group.
>A
A
You cannot move an existing instance into a placement group. Instances within a placement group generally have both a public and a private IP address. Communications across a public IP address are limited to 5Gbps or less. Low-latency, high-throughput communications between placement group members can only occur across the private interfaces, using the private IP addresses. These communications can be either 10Gbps or 20Gbps, and are limited by the instance's network configuration.
https://awsinsider.net/articles/2017/06/12/ec2-placement-groups.aspx

https://www.examtopics.com/discussions/amazon/view/5026-exam-aws-certified-solutions-architect-professional-topic-1/
502. A Solutions Architect has created an AWS CloudFormation template for a three-tier application that contains an Auto Scaling group of Amazon EC2 instances running a custom AMI.
The Solutions Architect wants to ensure that future updates to the custom AMI can be deployed to a running stack by first updating the template to refer to the new
AMI, and then invoking UpdateStack to replace the EC2 instances with instances launched from the new AMI.
How can updates to the AMI be deployed to meet these requirements?
A. Create a change set for a new version of the template, view the changes to the running EC2 instances to ensure that the AMI is correctly updated, and then execute the change set.
B. Edit the AWS::AutoScaling::LaunchConfiguration resource in the template, changing its DeletionPolicy to Replace.
C. Edit the AWS::AutoScaling::AutoScalingGroup resource in the template, inserting an UpdatePolicy attribute.
D. Create a new stack from the updated template. Once it is successfully deployed, modify the DNS records to point to the new stack and delete the old stack.
>C
Aws is C.
Without inserting an UpdatePolicy attribute to AWS::AutoScaling::LaunchConfiguration, execute the change set will only create new LaunchConfiguration and existing instances are not affected.

https://www.examtopics.com/discussions/amazon/view/5028-exam-aws-certified-solutions-architect-professional-topic-1/
503. A Solutions Architect is designing a multi-account structure that has 10 existing accounts. The design must meet the following requirements:
✑ Consolidate all accounts into one organization.
✑ Allow full access to the Amazon EC2 service from the master account and the secondary accounts.
✑ Minimize the effort required to add additional secondary accounts.
Which combination of steps should be included in the solution? (Choose two.)
A. Create an organization from the master account. Send invitations to the secondary accounts from the master account. Accept the invitations and create an OU.
B. Create an organization from the master account. Send a join request to the master account from each secondary account. Accept the requests and create an OU.
C. Create a VPC peering connection between the master account and the secondary accounts. Accept the request for the VPC peering connection.
D. Create a service control policy (SCP) that enables full EC2 access, and attach the policy to the OU.
E. Create a full EC2 access policy and map the policy to a role in each account. Trust every other account to assume the role.
>AD

https://www.examtopics.com/discussions/amazon/view/5140-exam-aws-certified-solutions-architect-professional-topic-1/
504. AnyCompany has acquired numerous companies over the past few years. The CIO for AnyCompany would like to keep the resources for each acquired company separate. The CIO also would like to enforce a chargeback model where each company pays for the AWS services it uses.
The Solutions Architect is tasked with designing an AWS architecture that allows AnyCompany to achieve the following:
✑ Implementing a detailed chargeback mechanism to ensure that each company pays for the resources it uses.
✑ AnyCompany can pay for AWS services for all its companies through a single invoice.
✑ Developers in each acquired company have access to resources in their company only.
✑ Developers in an acquired company should not be able to affect resources in their company only.
✑ A single identity store is used to authenticate Developers across all companies.
Which of the following approaches would meet these requirements? (Choose two.)
A. Create a multi-account strategy with an account per company. Use consolidated billing to ensure that AnyCompany needs to pay a single bill only.
B. Create a multi-account strategy with a virtual private cloud (VPC) for each company. Reduce impact across companies by not creating any VPC peering links. As everything is in a single account, there will be a single invoice. Use tagging to create a detailed bill for each company.
C. Create IAM users for each Developer in the account to which they require access. Create policies that allow the users access to all resources in that account. Attach the policies to the IAM user.
D. Create a federated identity store against the company's Active Directory. Create IAM roles with appropriate permissions and set the trust relationships with AWS and the identity store. Use AWS STS to grant users access based on the groups they belong to in the identity store.
E. Create a multi-account strategy with an account per company. For billing purposes, use a tagging solution that uses a tag to identify the company that creates each resource.
>AE
A. Create a multi-account strategy with an account per company. Use consolidated billing to ensure that AnyCompany needs to pay a single bill only.
D. Create a federated identity store against the companyג€™s Active Directory. Create IAM roles with appropriate permissions and set the trust relationships with AWS and the identity store. Use AWS STS to grant users access based on the groups they belong to in the identity store.


https://www.examtopics.com/discussions/amazon/view/5230-exam-aws-certified-solutions-architect-professional-topic-1/
505. A company deployed a three-tier web application in two regions: us-east-1 and eu-west-1. The application must be active in both regions at the same time. The database tier of the application uses a single Amazon RDS Aurora database globally, with a master in us-east-1 and a read replica in eu-west-1. Both regions are connected by a VPN.
The company wants to ensure that the application remains available even in the event of a region-level failure of all of the application's components. It is acceptable for the application to be in read-only mode for up to 1 hour. The company plans to configure two Amazon Route 53 record sets, one for each of the regions.
How should the company complete the configuration to meet its requirements while providing the lowest latency for the application end-users? (Choose two.)
A. Use failover routing and configure the us-east-1 record set as primary and the eu-west-1 record set as secondary. Configure an HTTP health check for the web application in us-east-1, and associate it to the us-east-1 record set.
B. Use weighted routing and configure each record set with a weight of 50. Configure an HTTP health check for each region, and attach it to the record set for that region.
C. Use latency-based routing for both record sets. Configure a health check for each region and attach it to the record set for that region.
D. Configure an Amazon CloudWatch alarm for the health checks in us-east-1, and have it invoke an AWS Lambda function that promotes the read replica in eu- west-1.
E. Configure Amazon RDS event notifications to react to the failure of the database in us-east-1 by invoking an AWS Lambda function that promotes the read replica in eu-west-1.
>`CD`
CD.
A\B: This would not be based on latency.
E: Amazon RDS uses the Amazon Simple Notification Service (Amazon SNS) to provide notification when an Amazon RDS event occurs. These notifications can be in any notification form supported by Amazon SNS for an AWS Region, such as an email, a text message, or a call to an HTTP endpoint. https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_Events.html


506. A company runs a Windows Server host in a public subnet that is configured to allow a team of administrators to connect over RDP to troubleshoot issues with hosts in a private subnet. The host must be available at all times outside of a scheduled maintenance window, and needs to receive the latest operating system updates within 3 days of release.
What should be done to manage the host with the LEAST amount of administrative effort?
A. Run the host in a single-instance AWS Elastic Beanstalk environment. Configure the environment with a custom AMI to use a hardened machine image from AWS Marketplace. Apply system updates with AWS Systems Manager Patch Manager.
B. Run the host on AWS WorkSpaces. Use Amazon WorkSpaces Application Manager (WAM) to harden the host. Configure Windows automatic updates to occur every 3 days.
C. Run the host in an Auto Scaling group with a minimum and maximum instance count of 1. Use a hardened machine image from AWS Marketplace. Apply system updates with AWS Systems Manager Patch Manager.
D. Run the host in AWS OpsWorks Stacks. Use a Chief recipe to harden the AMI during instance launch. Use an AWS Lambda scheduled event to run the Upgrade Operating System stack command to apply system updates.
>C


https://www.examtopics.com/discussions/amazon/view/16838-exam-aws-certified-solutions-architect-professional-topic-1/
543. A company has a data center that must be migrated to AWS as quickly as possible. The data center has a 500 Mbps AWS Direct Connect link and a separate, fully available 1 Gbps ISP connection. A Solutions Architect must transfer 20 TB of data from the data center to an Amazon S3 bucket.
What is the FASTEST way transfer the data?
A. Upload the data to the S3 bucket using the existing DX link.
B. Send the data to AWS using the AWS Import/Export service.
C. Upload the data using an 80 TB AWS Snowball device.
D. Upload the data to the S3 bucket using S3 Transfer Acceleration.
>D
Transfer Acceleration over a fully available 1 Gbps can theoretically move around 10TB/Day.

1 Gbps = (1024/8) MBPs = 128 MBps
(128 MBps * 3600 secs * 24 Hrs)/1024 = 10,800 GB/Day = 10TB/Day

Along with Transfer Acceleration, which provides a consistent experience, the entire data can be moved in 2 days. However AWS Import/Export (now snowball) takes around a week to make the data available on AWS. The Answer is D.

https://www.examtopics.com/discussions/amazon/view/27902-exam-aws-certified-solutions-architect-professional-topic-1/
567. A company wants to analyze log data using date ranges with a custom application running on AWS. The application generates about 10 GB of data every day, which is expected to grow. A Solutions Architect is tasked with storing the data in Amazon S3 and using Amazon Athena to analyze the data.
Which combination of steps will ensure optimal performance as the data grows? (Choose two.)
A. Store each object in Amazon S3 with a random string at the front of each key.
B. Store the data in multiple S3 buckets.
C. Store the data in Amazon S3 in a columnar format, such as Apache Parquet or Apache ORC.
D. Store the data in Amazon S3 in objects that are smaller than 10 MB.
E. Store the data using Apache Hive partitioning in Amazon S3 using a key that includes a date, such as dt=2019-02.

https://www.examtopics.com/discussions/amazon/view/68855-exam-aws-certified-solutions-architect-professional-topic-1/
800. A company has used infrastructure as code (IaC) to provision a set of two Amazon EC2 instances. The instances have remained the same for several years.
The company's business has grown rapidly in the past few months. In response the company's operations team has implemented an Auto Scaling group to manage the sudden increases in traffic. Company policy requires a monthly installation of security updates on all operating systems that are running.
The most recent security update required a reboot. As a result, the Auto Scaling group terminated the instances and replaced them with new, unpatched instances.
Which combination of steps should a solutions architect recommend to avoid a recurrence of this issue? (Choose two.)
A. Modify the Auto Scaling group by setting the Update policy to target the oldest launch configuration for replacement.
B. Create a new Auto Scaling group before the next patch maintenance. During the maintenance window, patch both groups and reboot the instances.
C. Create an Elastic Load Balancer in front of the Auto Scaling group. Configure monitoring to ensure that target group health checks return healthy after the Auto Scaling group replaces the terminated instances.
D. Create automation scripts to patch an AMI, update the launch configuration, and invoke an Auto Scaling instance refresh.
E. Create an Elastic Load Balancer in front of the Auto Scaling group. Configure termination protection on the instances.
> 看不懂，感觉AC还是合理的
Answer is A & C
To change the launch configuration for an Auto Scaling group, use an existing launch configuration as the basis for a new launch configuration. Then, update the Auto Scaling group to use the new launch configuration. After you change the launch configuration for an Auto Scaling group, any new instances are launched using the new configuration options, but existing instances are not affected. To update the existing instances, terminate them so that they are replaced by your Auto Scaling group, or allow auto scaling to gradually replace older instances with newer instances based on your termination policies.
https://docs.aws.amazon.com/autoscaling/ec2/userguide/change-launch-config.html


https://www.examtopics.com/discussions/amazon/view/69062-exam-aws-certified-solutions-architect-professional-topic-1/
801. A financial services company in North America plans to release a new online web application to its customers on AWS. The company will launch the application in the us-east-1 Region on Amazon EC2 instances. The application must be highly available and must dynamically scale to meet user traffic. The company also wants to implement a disaster recovery environment for the application in the us-west-1 Region by using active-passive failover.
Which solution will meet these requirements?
A. Create a VPC in us-east-1 and a VPC in us-west-1. Configure VPC peering. In the us-east-1 VPC, create an Application Load Balancer (ALB) that extends across multiple Availability Zones in both VPCs. Create an Auto Scaling group that deploys the EC2 instances across the multiple Availability Zones in both VPCs. Place the Auto Scaling group behind the ALB.
B. Create a VPC in us-east-1 and a VPC in us-west-1. In the us-east-1 VPC, create an Application Load Balancer (ALB) that extends across multiple Availability Zones in that VPC. Create an Auto Scaling group that deploys the EC2 instances across the multiple Availability Zones in the us-east-1 VPC. Place the Auto Scaling group behind the ALB. Set up the same configuration in the us-west-1 VPC. Create an Amazon Route 53 hosted zone. Create separate records for each ALB. Enable health checks to ensure high availability between Regions.
C. Create a VPC in us-east-1 and a VPC in us-west-1. In the us-east-1 VPC, create an Application Load Balancer (ALB) that extends across multiple Availability Zones in that VPC. Create an Auto Scaling group that deploys the EC2 instances across the multiple Availability Zones in the us-east-1 VPC. Place the Auto Scaling group behind the ALB. Set up the same configuration in the us-west-1 VPC. Create an Amazon Route 53 hosted zone. Create separate records for each ALB. Enable health checks and configure a failover routing policy for each record.
D. Create a VPC in us-east-1 and a VPC in us-west-1. Configure VPC peering. In the us-east-1 VPC, create an Application Load Balancer (ALB) that extends across multiple Availability Zones in both VPCs. Create an Auto Scaling group that deploys the EC2 instances across the multiple Availability Zones in both VPCs. Place the Auto Scaling group behind the ALB. Create an Amazon Route 53 hosted zone. Create a record for the ALB.


https://www.examtopics.com/discussions/amazon/view/69129-exam-aws-certified-solutions-architect-professional-topic-1/
802. A company's site reliability engineer is performing a review of Amazon FSx for Windows File Server deployments within an account that the company acquired.
Company policy states that all Amazon FSx file systems must be configured to be highly available across Availability Zones.
During the review, the site reliability engineer discovers that one of the Amazon FSx file systems used a deployment type of Single-AZ 2. A solutions architect needs to minimize downtime while aligning this Amazon FSx file system with company policy.
What should the solutions architect do to meet these requirements?
A. Reconfigure the deployment type to Multi-AZ for this Amazon FSx file system.
B. Create a new Amazon FSx file system with a deployment type of Multi-AZ. Use AWS DataSync to transfer data to the new Amazon FSx file system. Point users to the new location.
C. Create a second Amazon FSx file system with a deployment type of Single-AZ 2. Use AWS DataSync to keep the data in sync. Switch users to the second Amazon FSx file system in the event of failure.
D. Use the AWS Management Console to take a backup of the Amazon FSx file system. Create a new Amazon FSx file system with a deployment type of Multi- AZ. Restore the backup to the new Amazon FSx file system. Point users to the new location.


https://www.examtopics.com/discussions/amazon/view/69648-exam-aws-certified-solutions-architect-professional-topic-1/
803. A company's solutions architect is analyzing costs of a multi-application environment. The environment is deployed across multiple Availability Zones in a single
AWS Region. After a recent acquisition, the company manages two organizations in AWS Organizations. The company has created multiple service provider applications as AWS PrivateLink-powered VPC endpoint services in one organization. The company has created multiple service consumer applications in the other organization.
Data transfer charges are much higher than the company expected, and the solutions architect needs to reduce the costs. The solutions architect must recommend guidelines for developers to follow when they deploy services. These guidelines must minimize data transfer charges for the whole environment.
Which guidelines meet these requirements? (Choose two.)
A. Use AWS Resource Access Manager to share the subnets that host the service provider applications with other accounts in the organization.
B. Place the service provider applications and the service consumer applications in AWS accounts in the same organization.
C. Turn off cross-zone load balancing for the Network Load Balancer in all service provider application deployments.
D. Ensure that service consumer compute resources use the Availability Zone-specific endpoint service by using the endpoint's local DNS name.
E. Create a Savings Plan that provides adequate coverage for the organization's planned inter-Availability Zone data transfer usage.


https://www.examtopics.com/discussions/amazon/view/69172-exam-aws-certified-solutions-architect-professional-topic-1/
804. A company has an environment that has a single AWS account. A solutions architect is reviewing the environment to recommend what the company could improve specifically in terms of access to the AWS Management Console. The company's IT support workers currently access the console for administrative tasks, authenticating with named IAM users that have been mapped to their job role.
The IT support workers no longer want to maintain both their Active Directory and IAM user accounts. They want to be able to access the console by using their existing Active Directory credentials. The solutions architect is using AWS Single Sign-On (AWS SSO) to implement this functionality.
Which solution will meet these requirements MOST cost-effectively?
A. Create an organization in AWS Organizations. Turn on the AWS SSO feature in Organizations Create and configure a directory in AWS Directory Service for Microsoft Active Directory (AWS Managed Microsoft AD) with a two-way trust to the company's on-premises Active Directory. Configure AWS SSO and set the AWS Managed Microsoft AD directory as the identity source. Create permission sets and map them to the existing groups within the AWS Managed Microsoft AD directory.
B. Create an organization in AWS Organizations. Turn on the AWS SSO feature in Organizations Create and configure an AD Connector to connect to the company's on-premises Active Directory. Configure AWS SSO and select the AD Connector as the identity source. Create permission sets and map them to the existing groups within the company's Active Directory.
C. Create an organization in AWS Organizations. Turn on all features for the organization. Create and configure a directory in AWS Directory Service for Microsoft Active Directory (AWS Managed Microsoft AD) with a two-way trust to the company's on-premises Active Directory. Configure AWS SSO and select the AWS Managed Microsoft AD directory as the identity source. Create permission sets and map them to the existing groups within the AWS Managed Microsoft AD directory.
D. Create an organization in AWS Organizations. Turn on all features for the organization. Create and configure an AD Connector to connect to the company's on-premises Active Directory. Configure AWS SSO and select the AD Connector as the identity source. Create permission sets and map them to the existing groups within the company's Active Directory.
>D
enable all features
https://docs.aws.amazon.com/organizations/latest/userguide/orgs_manage_org_create.html#create-org
During an org creation the one is able to choose between all features or Consolidated Billing features only.

https://www.examtopics.com/discussions/amazon/view/69658-exam-aws-certified-solutions-architect-professional-topic-1/
805. A gaming company created a game leaderboard by using a Multi-AZ deployment of an Amazon RDS database. The number of users is growing, and the queries to get individual player rankings are getting slower over time. The company expects a surge in users for an upcoming version and wants to optimize the design for scalability and performance.
Which solution will meet these requirements?
A. Migrate the database to Amazon DynamoDB. Store the leaderboard data in two different tables. Use Apache HiveQL JOIN statements to build the leaderboard.
B. Keep the leaderboard data in the RDS DB instance. Provision a Multi-AZ deployment of an Amazon ElastiCache for Redis cluster.
C. Stream the leaderboard data by using Amazon Kinesis Data Firehose with an Amazon S3 bucket as the destination. Query the S3 bucket by using Amazon Athena for the leaderboard.
D. Add a read-only replica to the RDS DB instance. Add an RDS Proxy database proxy.
>B
感觉B更合理， D并没有缓存的作用，只是for connection

https://www.examtopics.com/discussions/amazon/view/69240-exam-aws-certified-solutions-architect-professional-topic-1/
806. A company runs a software-as-a-service (SaaS) application on AWS. The application consists of AWS Lambda functions and an Amazon RDS for MySQL Multi-
AZ database. During market events, the application has a much higher workload than normal. Users notice slow response times during the peak periods because of many database connections. The company needs to improve the scalable performance and availability of the database.
Which solution meets these requirements?
A. Create an Amazon CloudWatch alarm action that triggers a Lambda function to add an Amazon RDS for MySQL read replica when resource utilization hits a threshold.
B. Migrate the database to Amazon Aurora, and add a read replica. Add a database connection pool outside of the Lambda handler function.
C. Migrate the database to Amazon Aurora, and add a read replica. Use Amazon Route 53 weighted records.
D. Migrate the database to Amazon Aurora, and add an Aurora Replica. Configure Amazon RDS Proxy to manage database connection pools.
>D

https://www.examtopics.com/discussions/amazon/view/69140-exam-aws-certified-solutions-architect-professional-topic-1/
807. A company has an on-premises Microsoft SQL Server database that writes a nightly 200 GB export to a local drive. The company wants to move the backups to more robust cloud storage on Amazon S3. The company has set up a 10 Gbps AWS Direct Connect connection between the on-premises data center and AWS.
Which solution meets these requirements MOST cost-effectively?
A. Create a new S3 bucket. Deploy an AWS Storage Gateway file gateway within the VPC that is connected to the Direct Connect connection. Create a new SMB file share. Write nightly database exports to the new SMB file share.
B. Create an Amazon FSx for Windows File Server Single-AZ file system within the VPC that is connected to the Direct Connect connection. Create a new SMB file share. Write nightly database exports to an SMB file share on the Amazon FSx file system. Enable nightly backups.
C. Create an Amazon FSx for Windows File Server Multi-AZ file system within the VPC that is connected to the Direct Connect connection. Create a new SMB file share. Write nightly database exports to an SMB file share on the Amazon FSx file system. Enable nightly backups.
D. Create a new S3 bucket. Deploy an AWS Storage Gateway volume gateway within the VPC that is connected to the Direct Connect connection. Create a new SMB file share. Write nightly database exports to the new SMB file share on the volume gateway, and automate copies of this data to an S3 bucket.
>A

https://www.examtopics.com/discussions/amazon/view/69451-exam-aws-certified-solutions-architect-professional-topic-1/
808. A company has multiple AWS accounts. The company recently had a security audit that revealed many unencrypted Amazon Elastic Block Store (Amazon EBS) volumes attached to Amazon EC2 instances.
A solutions architect must encrypt the unencrypted volumes and ensure that unencrypted volumes will be detected automatically in the future. Additionally, the company wants a solution that can centrally manage multiple AWS accounts with a focus on compliance and security.
Which combination of steps should the solutions architect take to meet these requirements? (Choose two.)
A. Create an organization in AWS Organizations. Set up AWS Control Tower, and turn on the strongly recommended guardrails. Join all accounts to the organization. Categorize the AWS accounts into OUs.
B. Use the AWS CLI to list all the unencrypted volumes in all the AWS accounts. Run a script to encrypt all the unencrypted volumes in place.
C. Create a snapshot of each unencrypted volume. Create a new encrypted volume from the unencrypted snapshot. Detach the existing volume, and replace it with the encrypted volume.
D. Create an organization in AWS Organizations. Set up AWS Control Tower, and turn on the mandatory guardrails. Join all accounts to the organization. Categorize the AWS accounts into OUs.
E. Turn on AWS CloudTrail. Configure an Amazon EventBridge (Amazon CloudWatch Events) rule to detect and automatically encrypt unencrypted volumes.
>AC
mandatory guardrails 只能由AWS创建


https://www.examtopics.com/discussions/amazon/view/69262-exam-aws-certified-solutions-architect-professional-topic-1/
809. A company has a new application that needs to run on five Amazon EC2 instances in a single AWS Region. The application requires high-throughput, low-latency network connections between all of the EC2 instances where the application will run. There is no requirement for the application to be fault tolerant.
Which solution will meet these requirements?
A. Launch five new EC2 instances into a cluster placement group. Ensure that the EC2 instance type supports enhanced networking.
B. Launch five new EC2 instances into an Auto Scaling group in the same Availability Zone. Attach an extra elastic network interface to each EC2 instance.
C. Launch five new EC2 instances into a partition placement group. Ensure that the EC2 instance type supports enhanced networking.
D. Launch five new EC2 instances into a spread placement group. Attach an extra elastic network interface to each EC2 instance.
>A


https://www.examtopics.com/discussions/amazon/view/69670-exam-aws-certified-solutions-architect-professional-topic-1/
810. A media company is hosting a high-traffic news website on AWS. The website's front end is based solely on HTML and JavaScript. The company loads all dynamic content by using dynamic asynchronous JavaScript requests to a dedicated backend infrastructure.
The front end runs on four Amazon EC2 instances as web servers. The dynamic backend runs in containers on an Amazon Elastic Container Service (Amazon
ECS) cluster that uses an Auto Scaling group of EC2 instances. The ECS tasks are behind an Application Load Balancer (ALB).
Which solutions should a solutions architect recommend to optimize costs? (Choose two.)
A. Migrate the front end of the website to an Amazon S3 bucket Deploy an Amazon CloudFront distribution. Set the S3 bucket as the distribution's origin.
B. Deploy an Amazon CloudFront distribution. Configure the distribution to use the ALB endpoint as the origin.
C. Migrate the front-end services to the ECS cluster. Increase the minimum number of nodes in the Auto Scaling group.
D. Turn on Auto Scaling for the front-end EC2 instances. Configure a new listener rule on the ALB to serve the front end.
E. Migrate the backend of the website to an Amazon S3 bucket. Deploy an Amazon CloudFront distribution. Set the S3 bucket as the distribution's origin.
>AB
js is static file

https://www.examtopics.com/discussions/amazon/view/69499-exam-aws-certified-solutions-architect-professional-topic-1/
811. A company is building an application on AWS. The application sends logs to an Amazon Elasticsearch Service (Amazon ES) cluster for analysis. All data must be stored within a VPC.
Some of the company's developers work from home. Other developers work from three different company office locations. The developers need to access
Amazon ES to analyze and visualize logs directly from their local development machines.
Which solution will meet these requirements?
A. Configure and set up an AWS Client VPN endpoint. Associate the Client VPN endpoint with a subnet in the VPC. Configure a Client VPN self-service portal. Instruct the developers to connect by using the client for Client VPN.
B. Create a transit gateway, and connect it to the VPC. Create an AWS Site-to-Site VPN. Create an attachment to the transit gateway. Instruct the developers to connect by using an OpenVPN client.
C. Create a transit gateway, and connect it to the VPC. Order an AWS Direct Connect connection. Set up a public VIF on the Direct Connect connection. Associate the public VIF with the transit gateway. Instruct the developers to connect to the Direct Connect connection
D. Create and configure a bastion host in a public subnet of the VPC. Configure the bastion host security group to allow SSH access from the company CIDR ranges. Instruct the developers to connect by using SSH.
>A
TODO site to site vpn


https://www.examtopics.com/discussions/amazon/view/71951-exam-aws-certified-solutions-architect-professional-topic-1/
812. A company has created an OU in AWS Organizations for each of its engineering teams. Each OU owns multiple AWS accounts. The organization has hundreds of
AWS accounts.
A solutions architect must design a solution so that each OU can view a breakdown of usage costs across its AWS accounts.
Which solution meets these requirements?
A. Create an AWS Cost and Usage Report (CUR) for each OU by using AWS Resource Access Manager. Allow each team to visualize the CUR through an Amazon QuickSight dashboard.
B. Create an AWS Cost and Usage Report (CUR) from the AWS Organizations management account. Allow each team to visualize the CUR through an Amazon QuickSight dashboard.
C. Create an AWS Cost and Usage Report (CUR) in each AWS Organizations member account. Allow each team to visualize the CUR through an Amazon QuickSight dashboard.
D. Create an AWS Cost and Usage Report (CUR) by using AWS Systems Manager. Allow each team to visualize the CUR through Systems Manager OpsCenter dashboards.
>B
B is the only valid option to conclude all bills from all OUs.
D - is not possible how can you visualize CUR with OpsCenter?
A - RAM cant create CUR
C - Not efficient and not possible with organization since it creates one CUR for all accounts


https://www.examtopics.com/discussions/amazon/view/69108-exam-aws-certified-solutions-architect-professional-topic-1/
813. A company in the United States (US) has acquired a company in Europe. Both companies use the AWS Cloud. The US company has built a new application with a microservices architecture. The US company is hosting the application across five VPCs in the us-east-2 Region. The application must be able to access resources in one VPC in the eu-west-1 Region. However, the application must not be able to access any other VPCs.
The VPCs in both Regions have no overlapping CIDR ranges. All Accounts are already consolidated in one organization in AWS Organizations.
Which solution will meet these requirements MOST cost-effectively?
A. Create one transit gateway in eu-west-1. Attach the VPCs in us-east-2 and the VPC in eu-west-1 to the transit gateway. Create the necessary route entries in each VPC so that the traffic is routed through the transit gateway.
B. Create one transit gateway in each Region. Attach the involved subnets to the regional transit gateway. Create the necessary route entries in the associated route tables for each subnet so that the traffic is routed through the regional transit gateway. Peer the two transit gateways.
C. Create a full mesh VPC peering connection configuration between all the VPCs. Create the necessary route entries in each VPC so that the traffic is routed through the VPC peering connection.
D. Create one VPC peering connection for each VPC in us-east-2 to the VPC in eu-west-1. Create the necessary route entries in each VPC so that the traffic is routed through the VPC peering connection.
>D
D - is the most cost effective
A - not possible you cant attach VPCs from multi-regions to one transit GW
B - Can work but not cost effective you pay every hour for a transit GW attachments
C - Can work but no need for full mesh the requirement is for one VPC
TODO transit GW的限制

https://www.examtopics.com/discussions/amazon/view/70174-exam-aws-certified-solutions-architect-professional-topic-1/
814. A United Kingdom (UK) company recently completed a successful proof of concept in Amazon WorkSpaces. The company also has a large office in the United
States (US). Staff members from each office regularly travel between the two locations and need access to a corporate WorkSpace without any reconfiguration of their WorkSpaces client.
The company has purchased a domain by using Amazon Route 53 for the connection alias. The company will use a Windows profile and document management solution.
A solutions architect needs to design the full solution. The solution must use a configuration of WorkSpaces in two AWS Regions and must provide Regional resiliency.
Which solution will meet these requirements?
A. Create a connection alias in a UK Region and a US Region. Associate the connection alias with a directory in the UK Region. Configure the DNS service for the domain in the connection alias. Configure a geolocation routing policy. Distribute the connection string to the WorkSpaces users.
B. Create a connection alias in a UK Region. Associated the connection alias with a directory in the UK Region. Configure the DNS service for the domain in the connection alias. Configure a weighted routing policy, with the UK Region set to 1 and a US Region set to 255. Distribute the connection string for the UK Region to the WorkSpaces users.
C. Create a connection alias in a UK Region and a US Region. Associate the connection aliases with a directory in each Region. Configure the DNS service for the domain in the connection alias. Configure a geolocation routing policy. Distribute the connection string to the WorkSpaces users.
D. Create a connection alias in a US Region. Associated the connection alias with a directory in the UK Region. Configure the DNS service for the domain in the connection alias. Configure a multivalue answer routing policy. Distribute the connection string for the US Region to the WorkSpaces users.
>C
C
You must also create special FQDN-based registration codes called connection aliases. These connection aliases replace Region-specific registration codes for your WorkSpaces users. (The Region-specific registration codes remain valid; however, for cross-Region redirection to work, your users must use the FQDN instead as their registration code.)
After you've created your connection aliases, you associate them with your WorkSpaces directories in different Regions to create association pairs.
Each association pair has a primary Region and one or more failover Regions.


https://www.examtopics.com/discussions/amazon/view/69682-exam-aws-certified-solutions-architect-professional-topic-1/
815. A company has a serverless multi-tenant content management system on AWS. The architecture contains a web-based front end that interacts with an Amazon
API Gateway API that uses a custom AWS Lambda authorizer. The authorizer authenticates a user to its tenant ID and encodes the information in a JSON Web
Token (JWT) token. After authentication, each API call through API Gateway targets a Lambda function that interacts with a single Amazon DynamoDB table to fulfill requests.
To comply with security standards, the company needs a stronger isolation between tenants. The company will have hundreds of customers within the first year.
Which solution will meet these requirements with the LEAST operational overhead?
A. Create a DynamoDB table for each tenant by using the tenant ID in the table name. Create a service that uses the JWT token to retrieve the appropriate Lambda execution role that is tenant-specific. Attach IAM policies to the execution role to allow access only to the DynamoDB table for the tenant.
B. Add tenant ID information to the partition key of the DynamoDB table. Create a service that uses the JWT token to retrieve the appropriate Lambda execution role that is tenant-specific. Attach IAM policies to the execution role to allow access to items in the table only when the key matches the tenant ID.
C. Create a separate AWS account for each tenant of the application. Use dedicated infrastructure for each tenant. Ensure that no cross-account network connectivity exists.
D. Add tenant ID as a sort key in every DynamoDB table. Add logic to each Lambda function to use the tenant ID that comes from the JWT token as the sort key in every operation on the DynamoDB table.
>B
Tips: https://aws.amazon.com/blogs/apn/isolating-saas-tenants-with-dynamically-generated-iam-policies/
https://aws.amazon.com/blogs/apn/multi-tenant-storage-with-amazon-dynamodb/


https://www.examtopics.com/discussions/amazon/view/69242-exam-aws-certified-solutions-architect-professional-topic-1/
816. A company is running a custom database in the AWS Cloud. The database uses Amazon EC2 for compute and uses Amazon Elastic Block Store (Amazon EBS) for storage. The database runs on the latest generation of EC2 instances and uses a General Purpose SSD (gp2) EBS volume for data.
The current data volume has the following characteristics:
✑ The volume is 512 GB in size.
✑ The volume never goes above 256 GB utilization.
✑ The volume consistently uses around 1,500 IOPS.
A solutions architect needs to conduct an analysis of the current database storage layer and make a recommendation about ways to reduce cost.
Which solution will provide the MOST cost savings without impacting the performance of the database?
A. Convert the data volume to the Cloud HDD (sc1) type. Leave the volume as 512 GB. Set the volume IOPS to 1,500.
B. Convert the data volume to the Provisioned IOPS SSD (io2) type. Resize the volume to 256 GB. Set the volume IOPS to 1,500.
C. Convert the data volume to the Provisioned IOPS SSD (io2) Block Express type. Leave the volume as 512 GB. Set the volume IOPS to 1,500.
D. Convert the data volume to the General Purpose SSD (gp3) type. Resize the volume to 256 GB. Set the volume IOPS to 1,500.
>D



https://www.examtopics.com/discussions/amazon/view/81414-exam-aws-certified-solutions-architect-professional-topic-1/
900. A company has implemented a new security requirement. According to the new requirement, the company must scan all traffic from corporate AWS instances in the company's VPC for violations of the company's security policies. As a result of these scans, the company can block access to and from specific IP addresses.
To meet the new requirement, the company deploys a set of Amazon EC2 instances in private subnets to serve as transparent proxies. The company installs approved proxy server software on these EC2 instances. The company modifies the route tables on all subnets to use the corresponding EC2 instances with proxy software as the default route. The company also creates security groups that are compliant with the security policies and assigns these security groups to the EC2 instances.
Despite these configurations, the traffic of the EC2 instances in their private subnets is not being properly forwarded to the internet.
What should a solutions architect do to resolve this issue?
A. Disable source/destination checks on the EC2 instances that run the proxy software.
B. Add a rule to the security group that is assigned to the proxy EC2 instances to allow all traffic between instances that have this security group. Assign this security group to all EC2 instances in the VPC.
C. Change the VPC's DHCP options set. Set the DNS server options to point to the addresses of the proxy EC2 instances.
D. Assign one additional elastic network interface to each proxy EC2 instance. Ensure that one of these network interfaces has a route to the private subnets. Ensure that the other network interface has a route to the internet.
>A
This means that the instance must be the source or destination of any traffic it sends or receives. However, a NAT instance must be able to send and receive traffic when the source or destination is not itself. Therefore, you must disable source/destination checks on the NAT instance

https://www.examtopics.com/discussions/amazon/view/82497-exam-aws-certified-solutions-architect-professional-topic-1/
901. A company is running a web application in the AWS Cloud. The application consists of dynamic content that is created on a set of Amazon EC2 instances. The
EC2 instances run in an Auto Scaling group that is configured as a target group for an Application Load Balancer (ALB).
The company is using an Amazon CloudFront distribution to distribute the application globally. The CloudFront distribution uses the ALB as an origin. The company uses Amazon Route 53 for DNS and has created an A record of www.example.com for the CloudFront distribution.
A solutions architect must configure the application so that itis highly available and fault tolerant.
Which solution meets these requirements?
A. Provision a full, secondary application deployment in a different AWS Region. Update the Route 53 A record to be a failover record. Add both of the CloudFront distributions as values. Create Route 53 health checks.
B. Provision an ALB, an Auto Scaling group, and EC2 instances in a different AWS Region. Update the CloudFront distribution, and create a second origin for the new ALB. Create an origin group for the two origins. Configure one origin as primary and one origin as secondary.
C. Provision an Auto Scaling group and EC2 instances in a different AWS Region. Create a second target for the new Auto Scaling group in the ALB. Set up the failover routing algorithm on the ALB.
D. Provision a full, secondary application deployment in a different AWS Region. Create a second CloudFront distribution, and add the new application setup as an origin. Create an AWS Global Accelerator accelerator. Add both of the CloudFront distributions as endpoints.
>B
B- https://docs.aws.amazon.com/AmazonCloudFront/latest/DeveloperGuide/DownloadDistS3AndCustomOrigins.html
https://docs.aws.amazon.com/AmazonCloudFront/latest/DeveloperGuide/high_availability_origin_failover.html
You can set up CloudFront with origin failover for scenarios that require high availability. To get started, you create an origin group with two origins: a primary and a secondary. If the primary origin is unavailable, or returns specific HTTP response status codes that indicate a failure, CloudFront automatically switches to the secondary origin.

https://www.examtopics.com/discussions/amazon/view/78625-exam-aws-certified-solutions-architect-professional-topic-1/
902. A company is collecting a large amount of data from a fleet of IoT devices. Data is stored as Optimized Row Columnar (ORC) files in the Hadoop Distributed File
System (HDFS) on a persistent Amazon EMR cluster. The company's data analytics team queries the data by using SQL in Apache Presto deployed on the same
EMR cluster. Queries scan large amounts of data, always run for less than 15 minutes, and run only between 5 PM and 10 PM.
The company is concerned about the high cost associated with the current solution. A solutions architect must propose the most cost-effective solution that will allow SQL data queries.
Which solution will meet these requirements?
A. Store data in Amazon S3. Use Amazon Redshift Spectrum to query data.
B. Store data in Amazon S3. Use the AWS Glue Data Catalog and Amazon Athena to query data.
C. Store data in EMR File System (EMRFS). Use Presto in Amazon EMR to query data.
D. Store data in Amazon Redshift. Use Amazon Redshift to query data.


https://www.examtopics.com/discussions/amazon/view/80982-exam-aws-certified-solutions-architect-professional-topic-1/
903. A solutions architect is designing a data processing system that will use Amazon EC2 instances. Data that needs to be processed will wait in an Amazon Simple
Queue Service (Amazon SQS) queue. At least two data processing instances must run at all times.
Which combination of actions will meet these requirements MOST cost-effectively? (Choose two.)
A. Create a Spot Fleet with a target scaling policy that targets the acceptable backlog per instance. Request two On-Demand Instances for minimum capacity. Use Spot Instances for additional capacity.
B. Purchase two Reserved Instances for the target platform and instance type in the target AWS Region.
C. Create On-Demand Capacity Reservations for two instances for the target platform and instance type in the target AWS Region.
D. Create an Auto Scaling group that uses Spot Instance requests. Configure the scaling policy to scale with the size of the SQS queue. Set the minimum value to 2.
E. Provision two Dedicated Hosts. Configure AWS Batch to use Spot Instances to supply additional capacity.


https://www.examtopics.com/discussions/amazon/view/80440-exam-aws-certified-solutions-architect-professional-topic-1/
904. A financial services company loaded millions of historical stock trades into an Amazon DynamoDB table. The table uses on-demand capacity mode. Once each day at midnight, a few million new records are loaded into the table. Application read activity against the table happens in bursts throughout the day, and a limited set of keys are repeatedly looked up. The company needs to reduce costs associated with DynamoDB.
Which strategy should a solutions architect recommend to meet this requirement?
A. Deploy an Amazon ElastiCache cluster in front of the DynamoDB table.
B. Deploy DynamoDB Accelerator (DAX). Configure DynamoDB auto scaling. Purchase Savings Plans in Cost Explorer.
C. Use provisioned capacity mode. Purchase Savings Plans in Cost Explorer.
D. Deploy DynamoDB Accelerator (DAX). Use provisioned capacity mode. Configure DynamoDB auto scaling.

https://www.examtopics.com/discussions/amazon/view/78707-exam-aws-certified-solutions-architect-professional-topic-1/
905. A company wants to send data from its on-premises systems to Amazon S3 buckets. The company created the S3 buckets in three different accounts. The company must send the data privately without the data traveling across the internet. The company has no existing dedicated connectivity to AWS.
Which combination of steps should a solutions architect take to meet these requirements? (Choose two.)
A. Establish a networking account in the AWS Cloud. Create a private VPC in the networking account. Set up an AWS Direct Connect connection with a private VIF between the on-premises environment and the private VPC.
B. Establish a networking account in the AWS Cloud. Create a private VPC in the networking account. Set up an AWS Direct Connect connection with a public VIF between the on-premises environment and the private VPC.
C. Create an Amazon S3 interface endpoint in the networking account.
D. Create an Amazon S3 gateway endpoint in the networking account.
E. Establish a networking account in the AWS Cloud. Create a private VPC in the networking account. Peer VPCs from the accounts that host the S3 buckets with the VPC in the network account.

https://www.examtopics.com/discussions/amazon/view/79293-exam-aws-certified-solutions-architect-professional-topic-1/
906. A company wants to use a hybrid cloud architecture between an on-premises data center and AWS. The company already has deployed a multi-account structure in AWS Organizations while following the AWS Well-Architected Framework.
Due to strict security requirements, connectivity between the data center and AWS must be encrypted in transit. Only a single entry point into AWS is permitted from the data center. The data center must be able to access all the AWS accounts.
Which solution meets these requirements?
A. Connect the AWS accounts with AWS Transit Gateway. Establish an AWS Site-to-Site VPN connection with the data center, and attach the connection to the transit gateway. Route traffic from the data center to all AWS accounts.
B. Connect the AWS accounts with VPC peering. Establish an AWS Site-to-Site VPN connection with the data center. Route traffic from the data center to all AWS accounts.
C. Connect the AWS accounts with VPC peering. Establish an AWS Direct Connect connection to the closest AWS Region. Route traffic from the data center to all AWS accounts.
D. Connect the AWS accounts with AWS Transit Gateway. Establish an AWS Direct Connect connection to the closest AWS Region, and attach the connection to the transit gateway. Route traffic from the data center to all AWS accounts.

https://www.examtopics.com/discussions/amazon/view/80988-exam-aws-certified-solutions-architect-professional-topic-1/
907. A solutions architect works for a government agency that has strict disaster recovery requirements. All Amazon Elastic Block Store (Amazon EBS) snapshots are required to be saved in at least two additional AWS Regions. The agency also is required to maintain the lowest possible operational overhead.
Which solution meets these requirements?
A. Configure a policy in Amazon Data Lifecycle Manager (Amazon DLM) to run once daily to copy the EBS snapshots to the additional Regions.
B. Use Amazon EventBridge (Amazon CloudWatch Events) to schedule an AWS Lambda function to copy the EBS snapshots to the additional Regions.
C. Set up AWS Backup to create the EBS snapshots. Configure Amazon S3 cross-Region replication to copy the EBS snapshots to the additional Regions.
D. Schedule Amazon EC2 Image Builder to run once daily to create an AMI and copy the AMI to the additional Regions.

https://www.examtopics.com/discussions/amazon/view/80768-exam-aws-certified-solutions-architect-professional-topic-1/
908. A retail company has a small ecommerce web application that uses an Amazon RDS for PostgreSQL DB instance. The DB instance is deployed with the Multi-AZ option turned on.
Application usage recently increased exponentially, and users experienced frequent HTTP 503 errors. Users reported the errors, and the company's reputation suffered. The company could not identify a definitive root cause.
The company wants to improve its operational readiness and receive alerts before users notice an incident. The company also wants to collect enough information to determine the root cause of any future incident.
Which solution will meet these requirements with the LEAST operational overhead?
A. Turn on Enhanced Monitoring for the DB instance. Modify the corresponding parameter group to turn on query logging for all the slow queries. Create Amazon CloudWatch alarms. Set the alarms to appropriate thresholds that are based on performance metrics in CloudWatch.
B. Turn on Enhanced Monitoring and Performance Insights for the DB instance. Create Amazon CloudWatch alarms. Set the alarms to appropriate thresholds that are based on performance metrics in CloudWatch.
C. Turn on log exports to Amazon CloudWatch for the PostgreSQL logs on the DB instance. Analyze the logs by using Amazon Elasticsearch Service (Amazon ES) and Kibana. Create a dashboard in Kibana. Configure alerts that are based on the metrics that are collected.
D. Turn on Performance Insights for the DB instance. Modify the corresponding parameter group to turn on query logging for all the slow queries. Create Amazon CloudWatch alarms. Set the alarms to appropriate thresholds that are based on performance metrics in CloudWatch.


https://www.examtopics.com/discussions/amazon/view/80490-exam-aws-certified-solutions-architect-professional-topic-1/
909. A company is planning to set up a REST API application on AWS. The application team wants to set up a new identity store on AWS. The IT team does not want to maintain any infrastructure or servers for this deployment.
What is the MOST operationally efficient solution that meets these requirements?
A. Deploy the application as AWS Lambda functions. Set up Amazon API Gateway REST API endpoints for the application. Create a Lambda function, and configure a Lambda authorizer.
B. Deploy the application in AWS AppSync, and configure AWS Lambda resolvers. Set up an Amazon Cognito user pool, and configure AWS AppSync to use the user pool for authorization.
C. Deploy the application as AWS Lambda functions. Set up Amazon API Gateway REST API endpoints for the application. Set up an Amazon Cognito user pool, and configure an Amazon Cognito authorizer.
D. Deploy the application in Amazon Elastic Kubernetes Service (Amazon EKS) clusters. Set up an Application Load Balancer for the EKS pods. Set up an Amazon Cognito user pool and service pod for authentication.

https://www.examtopics.com/discussions/amazon/view/80491-exam-aws-certified-solutions-architect-professional-topic-1/
910. A company is using AWS Single Sign-On (AWS SSO) to centrally manage permissions and access to multiple AWS accounts in AWS Organizations. A solutions architect needs to provide users with granular access to AWS accounts based on different job functions.
What should the solutions architect do to meet these requirements?
A. Create an IAM group for each job function. In AWS SSO for the management account, create a permission set for each job function. Add users to the appropriate groups. Assign roles to the corresponding groups in all AWS accounts.
B. Create a group in AWS SSO for each job function. In AWS SSO for the management account, create a permission set for each job function. Add users to the appropriate groups. Assign groups to AWS accounts with corresponding permission sets.
C. Create an IAM role for each job function in all AWS accounts. Create a group in the management account for each job function. In AWS SSO for the management account, create a permission set for each job function.
D. Create an IAM role for each job function in the management account. In AWS SSO for the management account, create a permission set for each IAM role.


https://www.examtopics.com/discussions/amazon/view/82536-exam-aws-certified-solutions-architect-professional-topic-1/
911. A company has hundreds of AWS accounts. The company recently implemented a centralized internal process for purchasing new Reserved Instances and modifying existing Reserved Instances. This process requires all business units that want to purchase or modify Reserved Instances to submit requests to a dedicated team for procurement. Previously, business units directly purchased or modified Reserved Instances in their own respective AWS accounts autonomously.
A solutions architect needs to enforce the new process in the most secure way possible.
Which combination of steps should the solutions architect take to meet these requirements? (Choose two.)
A. Ensure that all AWS accounts are part of an organization in AWS Organizations with all features enabled.
B. Use AWS Config to report on the attachment of an IAM policy that denies access to the ec2:PurchaseReservedInstancesOffering action and the ec2:ModifyReservedInstances action.
C. In each AWS account, create an IAM policy that denies the ec2:PurchaseReservedInstancesOffering action and the ec2:ModifyReservedInstances action.
D. Create an SCP that denies the ec2:PurchaseReservedInstancesOffering action and the ec2:ModifyReservedInstances action. Attach the SCP to each OU of the organization.
E. Ensure that all AWS accounts are part of an organization in AWS Organizations that uses the consolidated billing feature.
>AD

https://www.examtopics.com/discussions/amazon/view/79896-exam-aws-certified-solutions-architect-professional-topic-1/ 
912. A company hosts its primary API on AWS by using an Amazon API Gateway API and AWS Lambda functions that contain the logic for the API methods. The company's internal applications use the API for core functionality and business logic. The company's customers use the API to access data from their accounts.
Several customers also have access to a legacy API that is running on a single standalone Amazon EC2 instance.
The company wants to increase the security for these APIs to better prevent denial of service (DoS) attacks, check for vulnerabilities, and guard against common exploits.
What should a solutions architect do to meet these requirements?
A. Use AWS WAF to protect both APIs. Configure Amazon Inspector to analyze the legacy API. Configure Amazon GuardDuty to monitor for malicious attempts to access the APIs.
B. Use AWS WAF to protect the API Gateway API. Configure Amazon Inspector to analyze both APIs. Configure Amazon GuardDuty to block malicious attempts to access the APIs.
C. Use AWS WAF to protect the API Gateway API. Configure Amazon Inspector to analyze the legacy API. Configure Amazon GuardDuty to monitor for malicious attempts to access the APIs.
D. Use AWS WAF to protect the API Gateway API. Configure Amazon Inspector to protect the legacy API. Configure Amazon GuardDuty to block malicious attempts to access the APIs.
>C

https://www.examtopics.com/discussions/amazon/view/82592-exam-aws-certified-solutions-architect-professional-topic-1/
913. A company is migrating its applications to the AWS Cloud. Each application will reside in its own AWS account after the migration. The applications will be hosted on Amazon EC2 Linux instances that need to be accessed through the shell for administration. The company's administrators want to use the AWS CLI from their laptops to interact with AWS and the EC2 instances.
The company is concerned that SSH access keys might be lost or become public. The company wants to avoid using long-term keys.
Which combination of steps should a solutions architect recommend to meet these requirements? (Choose three.)
A. Create subaccounts and cross-account roles for each of the applications. Create users. Assign cross-account roles to the users. Provide users with their initial credentials. B Configure AWS Single Sign-On. Create users. Assign the users the permission sets for the application accounts that they need to access. Provide users with their initial credentials.
B. Use AWS Systems Manager Session Manager to obtain shell access to the EC2 instances.
C. Create an organization in AWS Organizations with all features enabled to manage the accounts. Create subaccounts to host each of the applications.
D. Create an AWS Lambda function to rotate user access keys every 30 days.
E. Create an AWS Lambda function to rotate SSH keys for the EC2 instances every 30 days.
>`ABC`

https://www.examtopics.com/discussions/amazon/view/80634-exam-aws-certified-solutions-architect-professional-topic-1/   
914. A solutions architect has created a single VPC on AWS. The VPC has one internet gateway and one NAT gateway. The VPC extends across three Availability
Zones. Each Availability Zone includes one public subnet and one private subnet. The three private subnets contain Amazon EC2 instances that must be able to connect to the internet.
Which solution will increase the network resiliency of this architecture?
A. Add two NAT gateways so that each Availability Zone has a NAT gateway. Configure a route table for each private subnet to send traffic to the NAT gateway in the subnet's Availability Zone.
B. Add two NAT gateways so that each Availability Zone has a NAT gateway. Configure a route table for each public subnet to send traffic to the NAT gateway in the subnet's Availability Zone.
C. Add two internet gateways so that each Availability Zone has an internet gateway. Configure a route table for each private subnet to send traffic to the internet gateway in the subnet's Availability Zone.
D. Add two internet gateways so that each Availability Zone has an internet gateway. Configure a route table for each public subnet to send traffic to the internet gateway in the subnet's Availability Zone.
>A

https://www.examtopics.com/discussions/amazon/view/79898-exam-aws-certified-solutions-architect-professional-topic-1/
915. A company is running an application in the AWS Cloud. The company's security team must approve the creation of all new IAM users. When a new IAM user is created, all access for the user must be removed automatically. The security team must then receive a notification to approve the user. The company has a multi-
Region AWS CloudTrail trail in the AWS account.
Which combination of steps will meet these requirements? (Choose three.)
A. Create an Amazon EventBridge (Amazon CloudWatch Events) rule. Define a pattern with the detail-type value set to AWS API Call via CloudTrail and an eventName of CreateUser.
B. Configure CloudTrail to send a notification for the CreateUser event to an Amazon Simple Notification Service (Amazon SNS) topic.
C. Invoke a container that runs in Amazon Elastic Container Service (Amazon ECS) with AWS Fargate technology to remove access.
D. Invoke an AWS Step Functions state machine to remove access.
E. Use Amazon Simple Notification Service (Amazon SNS) to notify the security team.
F. Use Amazon Pinpoint to notify the security team.
>ADE
复习一下cloudtrail的使用

https://www.examtopics.com/discussions/amazon/view/80776-exam-aws-certified-solutions-architect-professional-topic-1/
916. A company is building dozens of new workloads by using a variety of AWS services. Each workload will belong to a separate business unit. The company needs to minimize costs as each business unit experiments with ways to innovate. The company also needs to maximize scalability for its security team so that the security team can identify and respond to threats as quickly as possible for all the workloads.
Which combination of actions should a solutions architect take to meet these requirements? (Choose three.)
A. Set up a multi-account environment by using AWS Organizations. Organize accounts into the following OUs: Security, Infrastructure, Workloads, and Exception.
B. Set up a multi-account environment by using AWS Organizations. Organize accounts into the following SCPs: Security, Infrastructure, Workloads, and Exception.
C. Configure AWS Trusted Advisor to invoke an AWS Lambda function to move an AWS account that reaches a predefined budget threshold into the Exception OU. Apply an SCP at the root of the organization with a condition that matches the Exception OU to limit usage to core services, including Amazon EC2, Amazon S3, and Amazon RDS.
D. Use AWS Budgets alerts to invoke an AWS Lambda function to move an AWS account that reaches a predefined budget threshold into the Exception OU. Apply an SCP to the Exception OU to limit usage to core services, including Amazon EC2, Amazon S3, and Amazon RDS.
E. Turn on Amazon GuardDuty in each account. Create an Amazon Simple Notification Service (Amazon SNS) topic. Subscribe the security team to the topic so that the security team can receive alerts.
F. Create a delegated administrator account for Amazon GuardDuty in the organization in AWS Organizations. Create an Amazon Simple Notification Service (Amazon SNS) topic in this account. Subscribe the security team to the topic so that the security team can receive alerts.
>ADF
很复杂的案例，是否需要亲自做一下g, inspector,guardduty

创建org
zhou.rui@prjphx.com 为主账号
使用root账号登录



https://www.examtopics.com/discussions/amazon/view/82812-exam-aws-certified-solutions-architect-professional-topic-1/
917. A company is migrating its development and production workloads to a new organization in AWS Organizations. The company has created a separate member account for development and a separate member account for production. Consolidated billing is inked to the management account. In the management account, a solutions architect needs to create an IAM user that can stop or terminate resources in both member accounts.
Which solution will meet this requirement?
A. Create an IAM user and a cross-account role in the management account. Configure the cross-account role with least privilege access to the member accounts.
B. Create an IAM user in each member account. In the management account, create a cross-account role that has least privilege access. Grant the IAM users access to the cross-account role by using a trust policy.
C. Create an IAM user in the management account. In the member accounts, create an IAM group that has least privilege access. Add the IAM user from the management account to each IAM group in the member accounts.
D. Create an IAM user in the management account. In the member accounts, create cross-account roles that have least privilege access. Grant the IAM user access to the role by using a trust policy.
>D
HOL hands-on-lab


https://www.examtopics.com/discussions/amazon/view/79190-exam-aws-certified-solutions-architect-professional-topic-1/
918. An online magazine will launch its latest edition this month. This edition will be the first to be distributed globally. The magazine's dynamic website currently uses an Application Load Balancer in front of the web tier, a fleet of Amazon EC2 instances for web and application servers, and Amazon Aurora MySQL. Portions of the website include static content and almost all traffic is read-only.
The magazine is expecting a significant spike in internet traffic when the new edition is launched. Optimal performance is a top priority for the week following the launch.
Which combination of steps should a solutions architect take to reduce system response times for a global audience? (Choose two.)
A. Use logical cross-Region replication to replicate the Aurora MySQL database to a secondary Region. Replace the web servers with Amazon S3. Deploy S3 buckets in cross-Region replication mode.
B. Ensure the web and application tiers are each in Auto Scaling groups. Introduce an AWS Direct Connect connection. Deploy the web and application tiers in Regions across the world.
C. Migrate the database from Amazon Aurora to Amazon RDS for MySQL. Ensure all three of the application tiers ג€" web, application, and database ג€" are in private subnets.
D. Use an Aurora global database for physical cross-Region replication. Use Amazon S3 with cross-Region replication for static content and resources. Deploy the web and application tiers in Regions across the world.
E. Introduce Amazon Route 53 with latency-based routing and Amazon CloudFront distributions. Ensure the web and application tiers are each in Auto Scaling groups.
>DE

https://www.examtopics.com/discussions/amazon/view/80782-exam-aws-certified-solutions-architect-professional-topic-1/
919. A company has introduced a new policy that allows employees to work remotely from their homes if they connect by using a VPN. The company is hosting internal applications with VPCs in multiple AWS accounts. Currently, the applications are accessible from the company's on-premises office network through an AWS Site- to-Site VPN connection. The VPC in the company's main AWS account has peering connections established with VPCs in other AWS accounts.
A solutions architect must design a scalable AWS Client VPN solution for employees to use while they work from home.
What is the MOST cost-effective solution that meets these requirements?
A. Create a Client VPN endpoint in each AWS account. Configure required routing that allows access to internal applications.
B. Create a Client VPN endpoint in the main AWS account. Configure required routing that allows access to internal applications.
C. Create a Client VPN endpoint in the main AWS account. Provision a transit gateway that is connected to each AWS account. Configure required routing that allows access to internal applications.
D. Create a Client VPN endpoint in the main AWS account. Establish connectivity between the Client VPN endpoint and the AWS Site-to-Site VPN.
>`B`
client VPN 没看懂

https://www.examtopics.com/discussions/amazon/view/80267-exam-aws-certified-solutions-architect-professional-topic-1/
920. A company's solutions architect is designing a disaster recovery (DR) solution for an application that runs on AWS. The application uses PostgreSQL 11.7 as its database. The company has an RPO of 30 seconds. The solutions architect must design a DR solution with the primary database in the us-east-1 Region and the failover database in the us-west-2 Region.
What should the solutions architect do to meet these requirements with minimum application change?
A. Migrate the database to Amazon RDS for PostgreSQL in us-east-1. Set up a read replica in us-west-2. Set the managed RPO for the RDS database to 30 seconds.
B. Migrate the database to Amazon RDS for PostgreSQL in us-east-1. Set up a standby replica in an Availability Zone in us-west-2. Set the managed RPO for the RDS database to 30 seconds.
C. Migrate the database to an Amazon Aurora PostgreSQL global database with the primary Region as us-east-1 and the secondary Region as us-west-2. Set the managed RPO for the Aurora database to 30 seconds.
D. Migrate the database to Amazon DynamoDB in us-east-1. Set up global tables with replica tables that are created in us-west-2.

https://www.examtopics.com/discussions/amazon/view/80274-exam-aws-certified-solutions-architect-professional-topic-1/
921. A company that designs multiplayer online games wants to expand its user base outside of Europe. The company transfers a significant amount of UDP traffic to keep all the live and interactive sessions of the games. The company has plans for rapid expansion and wants to build its architecture to provide an optimized online experience to its users.
Which architecture will meet these requirements with the LOWEST latency for users?
A. Set up a Multi-AZ environment in a single AWS Region. Use Amazon CloudFront to cache user sessions.
B. Set up environments in multiple AWS Regions. Create an accelerator in AWS Global Accelerator, and add endpoints from different Regions to it.
C. Set up environments in multiple AWS Regions. Use Amazon Route 53, and select latency-based routing.
D. Set up a Multi-AZ environment in a single AWS Region. Use AWS Lambda@Edge to update sessions closer to the users.

https://www.examtopics.com/discussions/amazon/view/78963-exam-aws-certified-solutions-architect-professional-topic-1/
922. A company is using a lift-and-shift strategy to migrate applications from several on-premises Windows servers to AWS. The Windows servers will be hosted on
Amazon EC2 instances in the us-east-1 Region.
The company's security policy allows the installation of migration tools on servers. The migration data must be encrypted in transit and encrypted at rest. The applications are business critical. The company needs to minimize the cutover window and minimize the downtime that results from the migration. The company wants to use Amazon CloudWatch and AWS CloudTrail for monitoring.
Which solution will meet these requirements?
A. Use AWS Application Migration Service (CloudEndure Migration) to migrate the Windows servers to AWS. Create a Replication Settings template. Install the AWS Replication Agent on the source servers.
B. Use AWS DataSync to migrate the Windows servers to AWS. Install the DataSync agent on the source servers. Configure a blueprint for the target servers. Begin the replication process.
C. Use AWS Server Migration Service (AWS SMS) to migrate the Windows servers to AWS. Install the SMS Connector on the source servers. Replicate the source servers to AWS. Convert the replicated volumes to AMIs to launch EC2 instances.
D. Use AWS Migration Hub to migrate the Windows servers to AWS. Create a project in Migration Hub. Track the progress of server migration by using the built- in dashboard.


https://www.examtopics.com/discussions/amazon/view/81267-exam-aws-certified-solutions-architect-professional-topic-1/
923. A company has set up a multi-account AWS environment by using AWS Control Tower. Each AWS account that AWS Control Tower creates has its own VPC.
The company is developing an application that will integrate with many microservices. The company has designated a specific account to host the application. The company will deploy the microservices on Amazon EC2 instances and will implement the microservices across multiple AWS accounts.
The microservices require a high degree of interconnectivity. The company needs a solution that will give the application the ability to communicate privately with the microservices. The solution also must minimize cost and operational overhead.
Which solution will meet these requirements?
A. Use AWS VPN CloudHub to connect the application VPC to all the other VPCs. Use a virtual private gateway to provide traffic flow between all the VPCs.
B. Create VPC peering connections between the application VPC and all the other VPCs. Update the security groups and route tables to allow traffic flow between all the VPCs.
C. Create a transit gateway in the application account. Attach the application VPC and all the other VPCs to the transit gateway. Create a transit gateway route table to direct traffic between the VPCs.
D. Share the application VPC with the other AWS accounts by using AWS Resource Access Manager (AWS RAM). Deploy the microservices in the shared VPC.

https://www.examtopics.com/discussions/amazon/view/80290-exam-aws-certified-solutions-architect-professional-topic-1/
924. A company is running an image-processing service in the AWS Cloud. Users upload images to an Amazon S3 bucket for processing. When an image is uploaded to the S3 bucket, several microservices that are based on AWS Lambda functions need to perform different processing tasks on the image. Each task's processing must start immediately after an image is uploaded.
Which solution will meet these requirements?
A. Configure each microservice to create an S3 event notification with its Lambda function as the destination.
B. Configure AWS CloudTrail event logging for Amazon S3. Create an Amazon EventBridge (Amazon CloudWatch Events) rule with an event pattern that matches PutObject API calls through CloudTrail. Register each microservice's Lambda function as a target for the rule.
C. Create an Amazon EventBridge (Amazon CloudWatch Events) rule with an event pattern for PutObject events in S3 event notifications. Configure each microservice to register an Amazon Simple Queue Service (Amazon SQS) queue as a target for the rule. Invoke the microservice's Lambda function from the SQS queue.
D. Create an S3 event notification with an Amazon Simple Notification Service (Amazon SNS) topic as the destination. Create an SNS subscription for each microservice's Lambda function.

https://www.examtopics.com/discussions/amazon/view/78964-exam-aws-certified-solutions-architect-professional-topic-1/
925. A company uses multiple AWS accounts in a single AWS Region. A solutions architect is designing a solution to consolidate logs generated by Elastic Load
Balancers (ELBs) in the AppDev, AppTest, and AppProd accounts. The logs should be stored in an existing Amazon S3 bucket named s3-elb-logs in the central
AWS account. The central account is used for log consolidation only and does not have ELBs deployed. ELB logs must be encrypted at rest.
Which combination of steps should the solutions architect take to build the solution? (Choose two.)
A. Update the S3 bucket policy for the s3-elb-logs bucket to allow the s3:PutBucketLogging action for the central AWS account ID.
B. Update the S3 bucket policy for the s3-elb-logs bucket to allow the s3:PutObject and s3:DeleteObject actions for the AppDev, AppTest, and AppProd account IDs.
C. Update the S3 bucket policy for the s3-elb-logs bucket to allow the s3:PutObject action for the AppDev, AppTest, and AppProd account IDs.
D. Enable access logging for the ELBs. Set the S3 location to the s3-elb-logs bucket.
E. Enable Amazon S3 default encryption using server-side encryption with S3 managed encryption keys (SSE-S3) for the s3-elb-logs S3 bucket.


https://www.examtopics.com/discussions/amazon/view/80083-exam-aws-certified-solutions-architect-professional-topic-1/
926. A medical company is running a REST API on a set of Amazon EC2 instances. The EC2 instances run in an Auto Scaling group behind an Application Load
Balancer (ALB). The ALB runs in three public subnets, and the EC2 instances run in three private subnets. The company has deployed an Amazon CloudFront distribution that has the ALB as the only origin.
Which solution should a solutions architect recommend to enhance the origin security?
A. Store a random string in AWS Secrets Manager. Create an AWS Lambda function for automatic secret rotation. Configure CloudFront to inject the random string as a custom HTTP header for the origin request. Create an AWS WAF web ACL rule with a string match rule for the custom header. Associate the web ACL with the ALB.
B. Create an AWS WAF web ACL rule with an IP match condition of the CloudFront service IP address ranges. Associate the web ACL with the ALB. Move the ALB into the three private subnets.
C. Store a random string in AWS Systems Manager Parameter Store. Configure Parameter Store automatic rotation for the string. Configure CloudFront to inject the random string as a custom HTTP header for the origin request. Inspect the value of the custom HTTP header, and block access in the ALB.
D. Configure AWS Shield Advanced. Create a security group policy to allow connections from CloudFront service IP address ranges. Add the policy to AWS Shield Advanced, and attach the policy to the ALB.


https://www.examtopics.com/discussions/amazon/view/81539-exam-aws-certified-solutions-architect-professional-topic-1/
927. A company has automated the nightly retraining of its machine learning models by using AWS Step Functions. The workflow consists of multiple steps that use
AWS Lambda. Each step can fail for various reasons, and any failure causes a failure of the overall workflow.
A review reveals that the retraining has failed multiple nights in a row without the company noticing the failure. A solutions architect needs to improve the workflow so that notifications are sent for all types of failures in the retraining process.
Which combination of steps should the solutions architect take to meet these requirements? (Choose three.)
A. Create an Amazon Simple Notification Service (Amazon SNS) topic with a subscription of type "Email" that targets the team's mailing list.
B. Create a task named "Email" that forwards the input arguments to the SNS topic.
C. Add a Catch field to all Task, Map, and Parallel states that have a statement of "ErrorEquals": [ "States.ALL" ] and "Next": "Email".
D. Add a new email address to Amazon Simple Email Service (Amazon SES). Verify the email address.
E. Create a task named "Email" that forwards the input arguments to the SES email address.
F. Add a Catch field to all Task, Map, and Parallel states that have a statement of "ErrorEquals": [ "States.Runtime" ] and "Next": "Email".

https://www.examtopics.com/discussions/amazon/view/82256-exam-aws-certified-solutions-architect-professional-topic-1/
928. A company has deployed its database on an Amazon RDS for MySQL DB instance in the us-east-1 Region. The company needs to make its data available to customers in Europe. The customers in Europe must have access to the same data as customers in the United States (US) and will not tolerate high application latency or stale data. The customers in Europe and the customers in the US need to write to the database. Both groups of customers need to see updates from the other group in real time.
Which solution will meet these requirements?
A. Create an Amazon Aurora MySQL replica of the RDS for MySQL DB instance. Pause application writes to the RDS DB instance. Promote the Aurora Replica to a standalone DB cluster. Reconfigure the application to use the Aurora database and resume writes. Add eu-west-1 as a secondary Region to the 06 cluster. Enable write forwarding on the DB cluster. Deploy the application in eu-west-1. Configure the application to use the Aurora MySQL endpoint in eu- west-1.
B. Add a cross-Region replica in eu-west-1 for the RDS for MySQL DB instance. Configure the replica to replicate write queries back to the primary DB instance. Deploy the application in eu-west-1. Configure the application to use the RDS for MySQL endpoint in eu-west-1.
C. Copy the most recent snapshot from the RDS for MySQL DB instance to eu-west-1. Create a new RDS for MySQL DB instance in eu-west-1 from the snapshot. Configure MySQL logical replication from us-east-1 to eu-west-1. Enable write forwarding on the DB cluster. Deploy the application in eu-west-1. Configure the application to use the RDS for MySQL endpoint in eu-west-1.
D. Convert the RDS for MySQL DB instance to an Amazon Aurora MySQL DB cluster. Add eu-west-1 as a secondary Region to the DB cluster. Enable write forwarding on the DB cluster. Deploy the application in eu-west-1. Configure the application to use the Aurora MySQL endpoint in eu-west-1.

https://www.examtopics.com/discussions/amazon/view/78709-exam-aws-certified-solutions-architect-professional-topic-1/
929. A company operates quick-service restaurants. The restaurants follow a predictable model with high sales traffic for 4 hours daily. Sales traffic is lower outside of those peak hours.
The point of sale and management platform is deployed in the AWS Cloud and has a backend that is based on Amazon DynamoDB. The database table uses provisioned throughput mode with 100,000 RCUs and 80,000 WCUs to match known peak resource consumption.
The company wants to reduce its DynamoDB cost and minimize the operational overhead for the IT staff.
Which solution meets these requirements MOST cost-effectively?
A. Reduce the provisioned RCUs and WCUs.
B. Change the DynamoDB table to use on-demand capacity.
C. Enable Dynamo DB auto scaling for the table.
D. Purchase 1-year reserved capacity that is sufficient to cover the peak load for 4 hours each day.


https://www.examtopics.com/discussions/amazon/view/80310-exam-aws-certified-solutions-architect-professional-topic-1/
930. A company is using AWS Organizations to manage multiple accounts. Due to regulatory requirements, the company wants to restrict specific member accounts to certain AWS Regions, where they are permitted to deploy resources. The resources in the accounts must be tagged, enforced based on a group standard, and centrally managed with minimal configuration.
What should a solutions architect do to meet these requirements?
A. Create an AWS Config rule in the specific member accounts to limit Regions and apply a tag policy.
B. From the AWS Billing and Cost Management console, in the management account, disable Regions for the specific member accounts and apply a tag policy on the root.
C. Associate the specific member accounts with the root. Apply a tag policy and an SCP using conditions to limit Regions.
D. Associate the specific member accounts with a new OU. Apply a tag policy and an SCP using conditions to limit Regions.


https://www.examtopics.com/discussions/amazon/view/79735-exam-aws-certified-solutions-architect-professional-topic-1/
931. A developer reports receiving an Error 403: Access Denied message when they try to download an object from an Amazon S3 bucket. The S3 bucket is accessed using an S3 endpoint inside a VPC, and is encrypted with an AWS KMS key. A solutions architect has verified that the developer is assuming the correct IAM role in the account that allows the object to be downloaded. The S3 bucket policy and the NACL are also valid.
Which additional step should the solutions architect take to troubleshoot this issue?
A. Ensure that blocking all public access has not been enabled in the S3 bucket.
B. Verify that the IAM role has permission to decrypt the referenced KMS key.
C. Verify that the IAM role has the correct trust relationship configured.
D. Check that local firewall rules are not preventing access to the S3 endpoint.

https://www.examtopics.com/discussions/amazon/view/79738-exam-aws-certified-solutions-architect-professional-topic-1/
932. A company deploys a new web application. As part of the setup, the company configures AWS WAF to log to Amazon S3 through Amazon Kinesis Data Firehose.
The company develops an Amazon Athena query that runs once daily to return AWS WAF log data from the previous 24 hours. The volume of daily logs is constant. However, over time, the same query is taking more time to run.
A solutions architect needs to design a solution to prevent the query time from continuing to increase. The solution must minimize operational overhead.
Which solution will meet these requirements?
A. Create an AWS Lambda function that consolidates each days AWS WAF logs into one log file.
B. Reduce the amount of data scanned by configuring AWS WAF to send logs to a different S3 bucket each day.
C. Update the Kinesis Data Firehose configuration to partition the data in Amazon S3 by date and time. Create external tables for Amazon Redshift. Configure Amazon Redshift Spectrum to query the data source.
D. Modify the Kinesis Data Firehose configuration and Athena table definition to partition the data by date and time. Change the Athena query to view the relevant partitions.


https://www.examtopics.com/discussions/amazon/view/80929-exam-aws-certified-solutions-architect-professional-topic-1/
933. A company manages an on-premises JavaScript front-end web application. The application is hosted on two servers secured with a corporate Active Directory.
The application calls a set of Java-based microservices on an application server and stores data in a clustered MySQL database. The application is heavily used during the day on weekdays. It is lightly used during the evenings and weekends.
Daytime traffic to the application has increased rapidly, and reliability has diminished as a result. The company wants to migrate the application to AWS with a solution that eliminates the need for server maintenance, with an API to securely connect to the microservices.
Which combination of actions will meet these requirements? (Choose three.)
A. Host the web application on Amazon S3. Use Amazon Cognito identity pools (federated identities) with SAML for authentication and authorization.
B. Host the web application on Amazon EC2 with Auto Scaling. Use Amazon Cognito federation and Login with Amazon for authentication and authorization.
C. Create an API layer with Amazon API Gateway. Rehost the microservices on AWS Fargate containers.
D. Create an API layer with Amazon API Gateway. Rehost the microservices on Amazon Elastic Container Service (Amazon ECS) containers.
E. Replatform the database to Amazon RDS for MySQL.
F. Replatform the database to Amazon Aurora MySQL Serverless.



https://www.examtopics.com/discussions/amazon/view/80991-exam-aws-certified-solutions-architect-professional-topic-1/
934. A company is running a data-intensive application on AWS. The application runs on a cluster of hundreds of Amazon EC2 instances. A shared file system also runs on several EC2 instances that store 200 TB of data. The application reads and modifies the data on the shared file system and generates a report. The job runs once monthly, reads a subset of the files from the shared file system, and takes about 72 hours to complete. The compute instances scale in an Auto Scaling group, but the instances that host the shared the system run continuously. The compute and storage instances are all in the same AWS Region.
A solutions architect needs to reduce costs by replacing the shared file system instances. The file system must provide high performance access to the needed data for the duration of the 72-hour run.
Which solution will provide the LARGEST overall cost reduction while meeting these requirements?
A. Migrate the data from the existing shared file system to an Amazon S3 bucket that uses the S3 Intelligent-Tiering storage class. Before the job runs each month, use Amazon FSx for Lustre to create a new file system with the data from Amazon S3 by using lazy loading. Use the new file system as the shared storage for the duration of the job. Delete the file system when the job is complete.
B. Migrate the data from the existing shared file system to a large Amazon Elastic Block Store (Amazon EBS) volume with Multi-Attach enabled. Attach the EBS volume to each of the instances by using a user data script in the Auto Scaling group launch template. Use the EBS volume as the shared storage for the duration of the job. Detach the EBS volume when the job is complete.
C. Migrate the data from the existing shared file system to an Amazon S3 bucket that uses the S3 Standard storage class. Before the job runs each month, use Amazon FSx for Lustre to create a new file system with the data from Amazon S3 by using batch loading. Use the new file system as the shared storage for the duration of the job. Delete the file system when the job is complete.
D. Migrate the data from the existing shared file system to an Amazon S3 bucket. Before the job runs each month, use AWS Storage Gateway to create a file gateway with the data from Amazon S3. Use the file gateway as the shared storage for the job. Delete the file gateway when the job is complete.

https://www.examtopics.com/discussions/amazon/view/83132-exam-aws-certified-solutions-architect-professional-topic-1/
935. A company is refactoring its on-premises order-processing platform in the AWS Cloud. The platform includes a web front end that is hosted on a fleet of VMs.
RabbitMQ to connect the front end to the backend, and a Kubernetes cluster to run a containerized backend system to process the orders. The company does not want to make any major changes to the application.
Which solution will meet these requirements with the LEAST operational overhead?
A. Create an AMI of the web server VM. Create an Amazon EC2 Auto Scaling group that uses the AMI and an Application Load Balancer. Set up Amazon MQ to replace the on-premises messaging queue. Configure Amazon Elastic Kubernetes Service (Amazon EKS) to host the order-processing backend.
B. Create a custom AWS Lambda runtime to mimic the web server environment. Create an Amazon API Gateway API to replace the front-end web servers. Set up Amazon MQ to replace the on-premises messaging queue. Configure Amazon Elastic Kubernetes Service (Amazon EKS) to host the order-processing backend.
C. Create an AMI of the web server VM. Create an Amazon EC2 Auto Scaling group that uses the AMI and an Application Load Balancer. Set up Amazon MQ to replace the on-premises messaging queue. Install Kuhernetes on a fleet of different EC2 instances to host the order-processing backend.
D. Create an AMI of the web server VM Create an Amazon EC2 Auto Scaling group that uses the AMI and an Application Load Balancer. Set up an Amazon Simple Queue Service (Amazon SQS) queue to replace the on-premises messaging queue, Configure Amazon Elastic Kubernetes Service (Amazon EKS) to host the order-processing backend.

https://www.examtopics.com/discussions/amazon/view/82131-exam-aws-certified-solutions-architect-professional-topic-1/
936. A company has an organization in AWS Organizations that has a large number of AWS accounts. One of the AWS accounts is designated as a transit account and has a transit gateway that is shared with all of the other AWS accounts. AWS Site-to-Site VPN connections are configured between all of the company's global offices and the transit account. The company has AWS Config enabled on all of its accounts.
The company's networking team needs to centrally manage a list of internal IP address ranges that belong to the global offices. Developers will reference this list to gain access to their applications securely.
Which solution meets these requirements with the LEAST amount of operational overhead?
A. Create a JSON file that is hosted in Amazon S3 and that lists all of the internal IP address ranges. Configure an Amazon Simple Notification Service (Amazon SNS) topic in each of the accounts that can be invoked when the JSON file is updated. Subscribe an AWS Lambda function to the SNS topic to update all relevant security group rules with the updated IP address ranges.
B. Create a new AWS Config managed rule that contains all of the internal IP address ranges. Use the rule to check the security groups in each of the accounts to ensure compliance with the list of IP address ranges. Configure the rule to automatically remediate any noncompliant security group that is detected.
C. In the transit account, create a VPC prefix list with all of the internal IP address ranges. Use AWS Resource Access Manager to share the prefix list with all of the other accounts. Use the shared prefix list to configure security group rules in the other accounts.
D. In the transit account, create a security group with all of the internal IP address ranges. Configure the security groups in the other accounts to reference the transit account's security group by using a nested security group reference of "<transit-account-id>/sg-1a2b3c4d".


https://www.examtopics.com/discussions/amazon/view/79933-exam-aws-certified-solutions-architect-professional-topic-1/
937. A company wants to move an application from on premises to the AWS Cloud. The application uses MySQL servers to store backend data. However, the application does not scale properly. The databases have become unresponsive as the user base has increased.
The company needs a solution to make the application highly available with low latency across multiple AWS Regions. The solution must require the least possible operational overhead and development effort.
Which solution will meet these requirements?
A. Create an Amazon RDS for MySQL DB cluster that includes a cross-Region read replica. Use AWS Database Migration Service (AWS DMS) to migrate existing databases.
B. Deploy Amazon DynamoDB with global tables. Use AWS Database Migration Service (AWS DMS) to migrate existing databases. Adapt the application to work with DynamoDB.
C. Create an Amazon Aurora global database. Use native MySQL tools to migrate existing databases.
D. Create MySQL servers on Amazon EC2 instances in two Regions. Set up asynchronous software replication across Regions.


https://www.examtopics.com/discussions/amazon/view/81635-exam-aws-certified-solutions-architect-professional-topic-1/
938. A company is running a serverless application that consists of several AWS Lambda functions and Amazon DynamoDB tables. The company has created new functionality that requires the Lambda functions to access an Amazon Neptune DB cluster. The Neptune DB cluster is located in three subnets in a VPC.
Which of the possible solutions will allow the Lambda functions to access the Neptune DB cluster and DynamoDB tables? (Choose two.)
A. Create three public subnets in the Neptune VPC, and route traffic through an internet gateway. Host the Lambda functions in the three new public subnets.
B. Create three private subnets in the Neptune VPC, and route internet traffic through a NAT gateway. Host the Lambda functions in the three new private subnets.
C. Host the Lambda functions outside the VPC. Update the Neptune security group to allow access from the IP ranges of the Lambda functions.
D. Host the Lambda functions outside the VPC. Create a VPC endpoint for the Neptune database, and have the Lambda functions access Neptune over the VPC endpoint.
E. Create three private subnets in the Neptune VPC. Host the Lambda functions in the three new isolated subnets. Create a VPC endpoint for DynamoDB, and route DynamoDB traffic to the VPC endpoint.


https://www.examtopics.com/discussions/amazon/view/81637-exam-aws-certified-solutions-architect-professional-topic-1/
939. A company wants to use Amazon WorkSpaces in combination with thin client devices to replace aging desktops. Employees use the desktops to access applications that work with clinical trial data. Corporate security policy states that access to the applications must be restricted to only company branch office locations. The company is considering adding an additional branch office in the next 6 months.
Which solution meets these requirements with the MOST operational efficiency?
A. Create an IP access control group rule with the list of public addresses from the branch offices. Associate the IP access control group with the WorkSpaces directory.
B. Use AWS Firewall Manner to create a web ACL rule with an IPSet with the list of public addresses from the branch office locations. Associate the web ACL with the WorkSpaces directory.
C. Use AWS Certificate Manager (ACM) to issue trusted device certificates to the machines deployed in the branch office locations. Enable restricted access on the WorkSpaces directory.
D. Create a custom WorkSpace image with Windows Firewall configured to restrict access to the public addresses of the branch offices. Use the image to deploy the WorkSpaces.

https://www.examtopics.com/discussions/amazon/view/81905-exam-aws-certified-solutions-architect-professional-topic-1/
940. A company provides specialized analytics services to customers. The analytics run on Amazon EC2 instances that need to be launched and terminated in response to requests from customers. A solutions architect is creating automation to manage the EC2 instances that handle customer requests. However, when the automation scripts attempt to launch many EC2 instances at the same time, a RequestLimitExceeded error frequently occurs.
What should the solutions architect do to handle this error?
A. Implement an exponential backoff strategy so that the API token bucket can refill.
B. Modify the EC2 instance launch configuration to install diagnostic tools on each instance to troubleshoot the issue.
C. Request an increase for API throttling quotas from the AWS Support Center.
D. Request an EC2 API quota increase through the Service Quotas console.

https://www.examtopics.com/discussions/amazon/view/79732-exam-aws-certified-solutions-architect-professional-topic-1/
941. A company has a media metadata extraction pipeline running on AWS. Notifications containing a reference to a file in Amazon S3 are sent to an Amazon Simple
Notification Service (Amazon SNS) topic. The pipeline consists of a number of AWS Lambda functions that are subscribed to the SNS topic. The Lambda functions extract the S3 tile and write metadata to an Amazon RDS PostgreSQL DB instance.
Users report that updates to the metadata are sometimes slow to appear or are lost. During these times, the CPU utilization on the database is high and the number of failed Lambda invocations increases.
Which combination of actions should a solutions architect take to help resolve this issue? (Choose two.)
A. Enable message delivery status on the SNS topic. Configure the SNS topic delivery policy to enable retries with exponential backoff.
B. Create an Amazon Simple Queue Service (Amazon SQS) FIFO queue and subscribe the queue to the SNS topic. Configure the Lambda functions to consume messages from the SQS queue.
C. Create an RDS proxy for the RDS instance. Update the Lambda functions to connect to the RDS instance using the proxy.
D. Enable the RDS Data API for the RDS instance. Update the Lambda functions to connect to the RDS instance using the Data API.
E. Create an Amazon Simple Queue Service (Amazon SQS) standard queue for each Lambda function and subscribe the queues to the SNS topic. Configure the Lambda functions to consume messages from their respective SQS queue.
>CE

https://www.examtopics.com/discussions/amazon/view/79730-exam-aws-certified-solutions-architect-professional-topic-1/
942. A company has VPC flow logs enabled for its NAT gateway. The company is seeing Action = ACCEPT for inbound traffic that comes from public IP address
198.51.100.2 destined for a private Amazon EC2 instance.
A solutions architect must determine whether the traffic represents unsolicited inbound connections from the internet. The first two octets of the VPC CIDR block are 203.0.
Which set of steps should the solutions architect take to meet these requirements?
A. Open the AWS CloudTrail console. Select the log group that contains the NAT gateway's elastic network interface and the private instance's elastic network interface. Run a query to filter with the destination address set as "like 203.0" and the source address set as "like 198.51.100.2". Run the stats command to filter the sum of bytes transferred by the source address and the destination address.
B. Open the Amazon CloudWatch console. Select the log group that contains the NAT gateway's elastic network interface and the private instance's elastic network interface. Run a query to filter with the destination address set as "like 203.0" and the source address set as "like 198.51.100.2". Run the stats command to filter the sum of bytes transferred by the source address and the destination address.
C. Open the AWS CloudTrail console. Select the log group that contains the NAT gateway's elastic network interface and the private instance's elastic network interface. Run a query to filter with the destination address set as "like 198.51.100.2" and the source address set as "like 203.0". Run the stats command to filter the sum of bytes transferred by the source address and the destination address.
D. Open the Amazon CloudWatch console. Select the log group that contains the NAT gateway's elastic network interface and the private instance's elastic network interface. Run a query to filter with the destination address set as "like 198.51.100.2" and the source address set as "like 203.0". Run the stats command to filter the sum of bytes transferred by the source address and the destination address.
>D

https://www.examtopics.com/discussions/amazon/view/81056-exam-aws-certified-solutions-architect-professional-topic-1/
943. A company is planning a migration from an on-premises data center to the AWS Cloud. The company plans to use multiple AWS accounts that are managed in an organization in AWS Organizations. The company will create a small number of accounts initially and will add accounts as needed. A solutions architect must design a solution that turns on AWS CloudTrail in all AWS accounts.
What is the MOST operationally efficient solution that meets these requirements?
A. Create an AWS Lambda function that creates a new CloudTrail trail in all AWS accounts in the organization. Invoke the Lambda function daily by using a scheduled action in Amazon EventBridge (Amazon CloudWatch Events).
B. Create a new CloudTrail trail in the organization's management account. Configure the trail to log all events for all AWS accounts in the organization.
C. Create a new CloudTrail trail in all AWS accounts in the organization. Create new trails whenever a new account is created. Define an SCP that prevents deletion or modification of trails. Apply the SCP to the root OU.
D. Create an AWS Systems Manager Automation runbook that creates a CloudTrail trail in all AWS accounts in the organization. Invoke the automation by using Systems Manager State Manager.
>B
Answer is B

Per AWS documentation at https://docs.aws.amazon.com/awscloudtrail/latest/userguide/creating-trail-organization.html:
"If you have created an organization in AWS Organizations, you can create a trail that logs all events for all AWS accounts in that organization. This is sometimes called an organization trail. You can also choose to edit an existing trail in the management account and apply it to an organization, making it an organization trail."

https://www.examtopics.com/discussions/amazon/view/82115-exam-aws-certified-solutions-architect-professional-topic-1/
944. A company uses AWS CloudFormation to deploy applications within multiple VPCs that are all attached to a transit gateway. Each VPC that sends traffic to the public internet must send the traffic through a shared services VPC. Each subnet within a VPC uses the default VPC route table, and the traffic is routed to the transit gateway. The transit gateway uses its default route table for any VPC attachment.
A security audit reveals that an Amazon EC2 instance that is deployed within a VPC can communicate with an EC2 instance that is deployed in any of the company's other VPCs. A solutions architect needs to limit the traffic between the VPCs. Each VPC must be able to communicate only with a predefined, limited set of authorized VPCs.
What should the solutions architect do to meet these requirements?
A. Update the network ACL of each subnet within a VPC to allow outbound traffic only to the authorized VPCs. Remove all deny rules except the default deny rule.
B. Update all the security groups that are used within a VPC to deny outbound traffic to security groups that are used within the unauthorized VPCs.
C. Create a dedicated transit gateway route table for each VPC attachment. Route traffic only to the authorized VPCs.
D. Update the main route table of each VPC to route traffic only to the authorized VPCs through the transit gateway.
>C
Q: How do I control which Amazon Virtual Private Clouds (VPCs) can communicate with each other?

You can segment your network by creating multiple route tables in an AWS Transit Gateway and associate Amazon VPCs and VPNs to them. This will allow you to create isolated networks inside an AWS Transit Gateway similar to virtual routing and forwarding (VRFs) in traditional networks. The AWS Transit Gateway will have a default route table. The use of multiple route tables is optional.


945. A company has developed a single-page web application in JavaScript. The source code is stored in a single Amazon S3 bucket in the us-east-1 Region. The company serves the web application to a global user base through Amazon CloudFront.
The company wants to experiment with two versions of the website without informing application users. Each version of the website will reside in its own S3 bucket. The company wants to determine which version is most successful in marketing a new product.
The solution must send application users that are based in Europe to the new website design. The solution must send application users that are based in the
United States to the current website design. However, some exceptions exist. The company needs to be able to redirect specific users to the new website design, regardless of the users' location.
Which solution meets these requirements?
A. Configure two CloudFront distributions. Configure a geolocation routing policy in Amazon Route 53 to route traffic to the appropriate CloudFront endpoint based on the location of clients.
B. Configure a single CloudFront distribution. Create a behavior with different paths for each version of the site. Configure Lambda@Edge on the default path to generate redirects and send the client to the correct version of the website.
C. Configure a single CloudFront distribution. Configure an alternate domain name on the distribution. Configure two behaviors to route users to the different S3 origins based on the domain name that the client uses in the HTTP request.
D. Configure a single CloudFront distribution with Lambda@Edge. Use Lambda@Edge to send user requests to different origins based on request attributes.
>D
some special user

https://www.examtopics.com/discussions/amazon/view/79636-exam-aws-certified-solutions-architect-professional-topic-1/
946. A company has an organization in AWS Organizations. The company has enabled trusted access between Organizations and AWS Resource Access Manager
(AWS RAM). The organization includes three AWS accounts, one each for shared services, development, and production. The shared services account has a
VPC.
A solutions architect needs to meet the following requirements:
* Configure access between the shared services VPC and the development and production accounts.
* Ensure that workloads in each account are deployed to at least three Availability Zones.
* Ensure that there is no direct communication between the development and production workloads.
Which combination of steps will meet these requirements? (Choose three.)
A. In the shared services VPC, create three subnets for three Availability Zones. Create one subnet in each Availability Zone.
B. In the shared services VPC, create six subnets for three Availability Zones. Create two subnets in each Availability Zone.
C. Configure network ACLs to prevent connectivity between the subnets in the development account and the production account.
D. Configure VPC default security group outbound rules to prevent connectivity between the subnets in the development account and the production account.
E. Use AWS RAM to share three subnets in different Availability Zones with the development account. Additionally, use AWS RAM to share the same three subnets with the production account.
F. Use AWS RAM to share three subnets in different Availability Zones with the development account. Additionally, use AWS RAM to share three other subnets in different Availability Zones with the production account.
>ACE
为何有需要多创建3个subnet?

==>done
/*-------------------------------------------------------------------------*\
|                                                                           |
|  FILE: ISARTP.H	                                                    |
|                                                                           |
|                                                                           |
|  Auto RTPatch Client Installer Header File                                |
|                                                                           |
|                                                                           |
|  (C) Copyright Pocket Soft, Inc. 2001-2002.  All Rights Reserved.         |
|                                                                           |
\*-------------------------------------------------------------------------*/

// Constants useful for formatting schedule settings
#define ARTP_SCHEDULE_MANUAL	0
#define ARTP_SCHEDULE_MONTHLY	1
#define ARTP_SCHEDULE_WEEKLY	2
#define ARTP_SCHEDULE_DAILY	3
#define ARTP_SCHEDULE_HOURLY	4
#define ARTP_SCHEDULE_SUNDAY	0
#define ARTP_SCHEDULE_MONDAY	1
#define ARTP_SCHEDULE_TUESDAY	2
#define ARTP_SCHEDULE_WEDNESDAY	3
#define ARTP_SCHEDULE_THURSDAY	4
#define ARTP_SCHEDULE_FRIDAY	5
#define ARTP_SCHEDULE_SATURDAY	6
#define ARTP_SCHEDULE_RANDOM	60 	

// constants for MakeUpdateShortcut
#define ARTP_MUS_QUIET	       0x1
#define ARTP_MUS_FAIL_NO_INET  0x2

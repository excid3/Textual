// Created by Satoshi Nakagawa <psychs AT limechat DOT net> <http://github.com/psychs/limechat>
// Modifications by Michael Morris <mikey AT codeux DOT com> <http://github.com/mikemac11/Textual>
// You can redistribute it and/or modify it under the new BSD license.

#import <Cocoa/Cocoa.h>

typedef enum {
	LINE_TYPE_SYSTEM,
	LINE_TYPE_ERROR,
	LINE_TYPE_CTCP,
	LINE_TYPE_REPLY,
	LINE_TYPE_ERROR_REPLY,
	LINE_TYPE_DCC_SEND_SEND,
	LINE_TYPE_DCC_SEND_RECEIVE,
	LINE_TYPE_PRIVMSG,
	LINE_TYPE_PRIVMSG_NH,
	LINE_TYPE_NOTICE,
	LINE_TYPE_ACTION,
	LINE_TYPE_ACTION_NH,
	LINE_TYPE_JOIN,
	LINE_TYPE_PART,
	LINE_TYPE_KICK,
	LINE_TYPE_QUIT,
	LINE_TYPE_KILL,
	LINE_TYPE_NICK,
	LINE_TYPE_MODE,
	LINE_TYPE_TOPIC,
	LINE_TYPE_INVITE,
	LINE_TYPE_WEBSITE,
	LINE_TYPE_DEBUG_SEND,
	LINE_TYPE_DEBUG_RECEIVE,
} LogLineType;

typedef enum {
	MEMBER_TYPE_NORMAL,
	MEMBER_TYPE_MYSELF,
} LogMemberType;

@interface LogLine : NSObject
{
	NSString* time;
	NSString* place;
	NSString* nick;
	NSString* body;
	LogLineType lineType;
	LogMemberType memberType;
	NSString* nickInfo;
	NSString* clickInfo;
	BOOL identified;
	NSInteger nickColorNumber;
	NSArray* keywords;
	NSArray* excludeWords;
}

@property (nonatomic, retain) NSString* time;
@property (nonatomic, retain) NSString* place;
@property (nonatomic, retain) NSString* nick;
@property (nonatomic, retain) NSString* body;
@property (nonatomic, assign) LogLineType lineType;
@property (nonatomic, assign) LogMemberType memberType;
@property (nonatomic, retain) NSString* nickInfo;
@property (nonatomic, retain) NSString* clickInfo;
@property (nonatomic, assign) BOOL identified;
@property (nonatomic, assign) NSInteger nickColorNumber;
@property (nonatomic, retain) NSArray* keywords;
@property (nonatomic, retain) NSArray* excludeWords;

+ (NSString*)lineTypeString:(LogLineType)type;
+ (NSString*)memberTypeString:(LogMemberType)type;

@end
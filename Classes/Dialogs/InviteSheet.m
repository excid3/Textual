// Created by Satoshi Nakagawa <psychs AT limechat DOT net> <http://github.com/psychs/limechat>
// Modifications by Michael Morris <mikey AT codeux DOT com> <http://github.com/mikemac11/Textual>
// You can redistribute it and/or modify it under the new BSD license.

#import "InviteSheet.h"

@interface InviteSheet (Private)
@end

@implementation InviteSheet

@synthesize nicks;
@synthesize uid;

- (id)init
{
	if (self = [super init]) {
		[NSBundle loadNibNamed:@"InviteSheet" owner:self];
	}
	return self;
}

- (void)dealloc
{
	[nicks release];
	[super dealloc];
}

- (void)startWithChannels:(NSArray*)channels
{
	NSString* target;
	if (nicks.count == 1) {
		target = [nicks safeObjectAtIndex:0];
	} else if (nicks.count == 2) {
		NSString* first = [nicks safeObjectAtIndex:0];
		NSString* second = [nicks safeObjectAtIndex:1];
		target = [NSString stringWithFormat:TXTLS(@"INVITE_SHEET_TWO_PEOPLE"), first, second];
	} else {
		target = [NSString stringWithFormat:TXTLS(@"INVITE_SHEET_MULTIPLE_PEOPLE"), nicks.count];
	}
	titleLabel.stringValue = [NSString stringWithFormat:TXTLS(@"INVITE_SHEET_TARGET_DESC"), target];
	
	for (NSString* s in channels) {
		[channelPopup addItemWithTitle:s];
	}
	
	[self startSheet];
}

- (void)invite:(id)sender
{
	NSString* channelName = [[channelPopup selectedItem] title];
	
	if ([delegate respondsToSelector:@selector(inviteSheet:onSelectChannel:)]) {
		[delegate inviteSheet:self onSelectChannel:channelName];
	}
	
	[self endSheet];
}

#pragma mark -
#pragma mark NSWindow Delegate

- (void)windowWillClose:(NSNotification*)note
{
	if ([delegate respondsToSelector:@selector(inviteSheetWillClose:)]) {
		[delegate inviteSheetWillClose:self];
	}
}

@synthesize titleLabel;
@synthesize channelPopup;
@end
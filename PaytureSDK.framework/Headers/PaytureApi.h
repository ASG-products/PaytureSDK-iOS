//
//  PaytureApi.h
//  Payture
//
//  Created by Ilya Fedorov on 06.02.2020.
//  Copyright © 2020 Payture. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaytureChequeObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Delegate for payments results feedback
 */
@protocol PaytureApiDelegate <NSObject>

/**
 Payment worderId is completed successfully
 */
-(void)payturePaymentCompleted:(NSString*)orderId;

@optional

@end

/**
 Class for work with Payture API
 
 You must input a few parameters from Payture support for correct work
 */
@interface PaytureApi : NSObject

@property (nullable, nonatomic, weak)   id<PaytureApiDelegate> delegate;

/**
 Initialize API
 
 First step, you must enter environment parameter for working with Payture system. This parameter does not change and is generated once.
 
 @param environment Environment value from Payture support
 
 */
-(void)initializeWithEnvironment:(NSString*)environment;

/**
 Set user data and terminal for payments
 
 Second step, you must enter user data from your databse and terminal parameter from payture support.
 
 @param userLogin User login
 @param userPassword User password
 @param userPhoneNumber User phone number
 @param userEmail User email
 @param terminal Terminal value for payments. This parameter does not change, but, theoretically, it may change in future versions
 
 */
-(void)setUserWithLogin:(NSString*)userLogin userPassword:(NSString*)userPassword userPhoneNumber:(nullable NSString*)userPhoneNumber userEmail:(nullable NSString*)userEmail forTerminal:(NSString*)terminal;

/**
 Make payment via eWallet API
 
 @param orderId Payment's order identifier
 @param productName Product's name for display to user in payments view
 @param amount Amount of money in pennies
 @param cheque Cheque data in base64 string
 
 */
-(void)eWalletPayWithOrderId:(NSString*)orderId productName:(NSString*)productName amount:(NSInteger)amount cheque:(nullable NSString*)cheque;

+ (PaytureApi*)sharedInstance;

@end

NS_ASSUME_NONNULL_END

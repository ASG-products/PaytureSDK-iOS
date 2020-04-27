//
//  ASGViewController.m
//  PaytureSDK
//
//  Created by Ilya Fedorov on 04/26/2020.
//  Copyright (c) 2020 Ilya Fedorov. All rights reserved.
//

#import "ASGViewController.h"
#import <PaytureSDK/PaytureSDK.h>

@interface ASGViewController ()

@end

@implementation ASGViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.

    [PaytureApi.sharedInstance initializeWithEnvironment:@"ENVIRONMENT"];
    [PaytureApi.sharedInstance setUserWithLogin:@"USER@EMAIL.com" userPassword:@"USER_PASSWORD" userPhoneNumber:nil userEmail:nil forTerminal:@"TERMINAL_FROM_PAYTURE"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)buyButtonClicked:(id)sender {
    
    [PaytureApi.sharedInstance eWalletPayWithOrderId:[NSUUID UUID].UUIDString productName:@"A pie" amount:8900 cheque:nil];

    //  Work with cheque
//    PaytureChequePositionObject *chequePosition = [[PaytureChequePositionObject alloc] initWithQuantity:1.0 price:89.00 tax:PaytureTaxTypeNDSEqual20Percents text:@"A pie"];
//    PaytureChequeObject *cheque = [[PaytureChequeObject alloc] initWithPositions:@[chequePosition] customerContact:@"CUSTOMER@EMAIL.COM"];
//    [PaytureApi.sharedInstance eWalletPayWithOrderId:[NSUUID UUID].UUIDString productName:@"A pie" amount:8900 cheque:[cheque base64Cheque]];

}

@end

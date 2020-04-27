# PaytureSDK

A library for payments via Payture for iOS devices 

[![Version](https://img.shields.io/cocoapods/v/PaytureSDK.svg?style=flat)](https://cocoapods.org/pods/PaytureSDK)
[![License](https://img.shields.io/cocoapods/l/PaytureSDK.svg?style=flat)](https://raw.githubusercontent.com/ASG-products/PaytureSDK-iOS/master/LICENSE)
[![Platform](https://img.shields.io/cocoapods/p/PaytureSDK.svg?style=flat)](https://cocoapods.org/pods/PaytureSDK)


## Preview

### iPhone

<p align="center"><img src="https://github.com/ASG-products/PaytureSDK-iOS/blob/master/Demo/iPhone_capture.gif" width="214"/></p>


## Installation

PaytureSDK is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'PaytureSDK'
```

Add header file:

```
#import <PaytureSDK/PaytureSDK.h>
``` 

## Usage

### Initialization

```
[PaytureApi.sharedInstance initializeWithEnvironment:@"ENVIRONMENT"];
[PaytureApi.sharedInstance setUserWithLogin:@"USER@EMAIL.com" userPassword:@"USER_PASSWORD" userPhoneNumber:nil userEmail:nil forTerminal:@"TERMINAL_FROM_PAYTURE"];
``` 

### Make a payment

```
[PaytureApi.sharedInstance eWalletPayWithOrderId:[NSUUID UUID].UUIDString productName:@"A pie" amount:8900 cheque:nil];
``` 

### Cheque

For more details about cheque you may see at [Payture API](https://payture.com/api/#kassy-fz54_cheque-format-with-payment_)

A simple cheque usage:

```
PaytureChequePositionObject *chequePosition = [[PaytureChequePositionObject alloc] initWithQuantity:1.0 price:89.00 tax:PaytureTaxTypeNDSEqual20Percents text:@"A pie"];
PaytureChequeObject *cheque = [[PaytureChequeObject alloc] initWithPositions:@[chequePosition] customerContact:@"CUSTOMER@EMAIL.COM"];

[PaytureApi.sharedInstance eWalletPayWithOrderId:[NSUUID UUID].UUIDString productName:@"A pie" amount:8900 cheque:[cheque base64Cheque]];
``` 

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.


## Author

Ilya Fedorov, ilya.fedorov@antares-software.ru

## License

PaytureSDK is available under the MIT license. See the [LICENSE](https://raw.githubusercontent.com/ASG-products/PaytureSDK-iOS/master/LICENSE) file for more info.

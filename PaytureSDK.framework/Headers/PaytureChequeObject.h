//
//  PaytureChequeObject.h
//  PaytureExample
//
//  Created by Ilya Fedorov on 19.03.2020.
//  Copyright © 2020 Payture. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, PaytureTaxType) {
    PaytureTaxTypeNDSEqual20Percents = 1,
    PaytureTaxTypeNDSEqual10Percents = 2,
    PaytureTaxTypeNDSEqual20_120 = 3,
    PaytureTaxTypeNDSEqual10_110 = 4,
    PaytureTaxTypeNDSEqual0Percents = 5,
    PaytureTaxTypeNoNDS = 6
};

typedef NS_ENUM(NSInteger, PaytureAgentType) {
    PaytureAgentTypeBankPaymentAgent = 1,
    PaytureAgentTypeBankPaymentSubagent = 2,
    PaytureAgentTypePaymentAgent = 4,
    PaytureAgentTypePaymentSubagent = 8,
    PaytureAgentTypeAttorney = 16,
    PaytureAgentTypeComissionAgent = 32,
    PaytureAgentTypeOtherAgent = 64
};

typedef NS_ENUM(NSInteger, PayturePaymentMethodType) {
    PayturePaymentMethodTypeFullPrepayment = 1,
    PayturePaymentMethodTypePartialPrepayment = 2,
    PayturePaymentMethodTypePrepaidExpense = 3,
    PayturePaymentMethodTypeFullCalculation = 4,
    PayturePaymentMethodTypePartialSettlementAndCredit = 5,
    PayturePaymentMethodTypeCreditTransfer = 6,
    PayturePaymentMethodTypeLoanRepayment = 7
};

typedef NS_ENUM(NSInteger, PayturePaymentType) {
    PayturePaymentTypeCash = 1,
    PayturePaymentTypeCashless = 2,
    PayturePaymentTypePrepaidExpense = 14,
    PayturePaymentTypeCredit = 15,
    PayturePaymentTypeCounterProvision = 16
};

typedef NS_ENUM(NSInteger, PayturePaymentSubjectType) {
    PayturePaymentSubjectTypeProduct = 1,
    PayturePaymentSubjectTypeExcisableProduct = 2,
    PayturePaymentSubjectTypeWork = 3,
    PayturePaymentSubjectTypeService = 4,
    PayturePaymentSubjectTypeGamblingBet = 5,
    PayturePaymentSubjectTypeGamblingWin = 6,
    PayturePaymentSubjectTypeLotteryTicket = 7,
    PayturePaymentSubjectTypeLotteryWin = 8,
    PayturePaymentSubjectTypeRIDprovision = 9,
    PayturePaymentSubjectTypePayment = 10,
    PayturePaymentSubjectTypeAgentComission = 11,
    PayturePaymentSubjectTypeCompoundSubjectOfCalculation = 12,
    PayturePaymentSubjectTypeOtherSubjectOfCalculation = 13
};


@interface PaytureChequeAgentInfoObject : NSObject

@property (nonatomic) NSString *paymentAgentOperation;
@property (nonatomic) NSArray<NSString*>* paymentAgentPhoneNumbers;
@property (nonatomic) NSString *paymentOperatorName;
@property (nonatomic) NSString *paymentOperatorAddress;
@property (nonatomic) NSString *paymentOperatorINN;
@property (nonatomic) NSArray<NSString*>* paymentOperatorPhoneNumbers;
@property (nonatomic) NSArray<NSString*>* paymentTransferOperatorPhoneNumbers;

@end


@interface PaytureChequeSupplierInfoObject : NSObject

@property (nonatomic) NSString *name;
@property (nonatomic) NSArray<NSString*>* phoneNumbers;

@end


/**
 Cheque's position class
 */
@interface PaytureChequePositionObject : NSObject

@property (nonatomic) float quantity;
@property (nonatomic) float price;
@property (nonatomic) PaytureTaxType tax;
@property (nonatomic) NSString *text;

//  optional attributes
@property (nonatomic) NSString *additionalAttribute;
@property (nonatomic) NSNumber *agentType;
@property (nonatomic) PaytureChequeAgentInfoObject *agentInfo;
@property (nonatomic) PayturePaymentMethodType paymentMethodType;
@property (nonatomic) NSString *customsDeclarationNumber;
@property (nonatomic) NSNumber *excise;
@property (nonatomic) NSString *manufacturerCountryCode;
@property (nonatomic) PayturePaymentSubjectType paymentSubjectType;
@property (nonatomic) NSString *nomenclatureCode;
@property (nonatomic) NSString *supplierINN;
@property (nonatomic) PaytureChequeSupplierInfoObject *supplierInfo;
@property (nonatomic) NSString *unitOfMeasurement;

-(instancetype)initWithQuantity:(float)quantity price:(float)price tax:(PaytureTaxType)tax text:(NSString*)text;

@end


@interface PaytureChequePaymentObject : NSObject

@property (nonatomic) PayturePaymentType type;
@property (nonatomic) float amount;

@end


@interface PaytureChequeAdditionalMessageObject : NSObject

@property (nonatomic) NSString *key;
@property (nonatomic) NSString *value;

@end


@interface PaytureChequeAdditionalUserAttributeObject : NSObject

@property (nonatomic) NSString *name;
@property (nonatomic) NSString *value;

@end



/**
 Class for work with cheques
 
 More details you can read at: https://payture.com/api/#kassy-fz54_cheque-format-with-payment_
 
 */
@interface PaytureChequeObject : NSObject

/** Arrays of cheque's positions objects  */
@property (nonatomic) NSArray<PaytureChequePositionObject*>* positions;

/** Customer's email or phone. Cheque will be sent to this contact */
@property (nonatomic) NSString *customerContact;

//  optional attributes
/** Payments */
@property (nonatomic) NSArray<PaytureChequePaymentObject*>* payments;
/** Email's sybject or SMSs text */
@property (nonatomic) NSString *message;
@property (nonatomic) NSString *group;
@property (nonatomic) NSString *templateTag;
@property (nonatomic) NSString *templateLang;
@property (nonatomic) NSArray<PaytureChequeAdditionalMessageObject*>* additionalMessages;
@property (nonatomic) NSString *additionalAttribute;
@property (nonatomic) PaytureChequeAdditionalUserAttributeObject *additionalUserAttribute;
@property (nonatomic) NSNumber *agentType;
@property (nonatomic) NSString *automatNumber;
@property (nonatomic) NSString *customer;
@property (nonatomic) NSString *customerINN;
@property (nonatomic) NSString *paymentAgentOperation;
@property (nonatomic) NSArray<NSString*>* paymentAgentPhoneNumbers;
@property (nonatomic) NSString *paymentOperatorName;
@property (nonatomic) NSString *paymentOperatorAddress;
@property (nonatomic) NSString *paymentOperatorINN;
@property (nonatomic) NSArray<NSString*>* paymentOperatorPhoneNumbers;
@property (nonatomic) NSArray<NSString*>* paymentTransferOperatorPhoneNumbers;
@property (nonatomic) NSString *settlementAddress;
@property (nonatomic) NSString *settlementPlace;
@property (nonatomic) NSArray<NSString*>* supplierPhoneNumbers;


-(instancetype)initWithPositions:(NSArray<PaytureChequePositionObject*>*)positions customerContact:(NSString *)customerContact;
-(NSString*)base64Cheque;

@end

NS_ASSUME_NONNULL_END

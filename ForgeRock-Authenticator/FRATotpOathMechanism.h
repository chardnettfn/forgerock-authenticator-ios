/*
 * The contents of this file are subject to the terms of the Common Development and
 * Distribution License (the License). You may not use this file except in compliance with the
 * License.
 *
 * You can obtain a copy of the License at legal/CDDLv1.0.txt. See the License for the
 * specific language governing permission and limitations under the License.
 *
 * When distributing Covered Software, include this CDDL Header Notice in each file and include
 * the License file at legal/CDDLv1.0.txt. If applicable, add the following below the CDDL
 * Header, with the fields enclosed by brackets [] replaced by your own identifying
 * information: "Portions copyright [year] [name of copyright owner]".
 *
 * Copyright 2016 ForgeRock AS.
 */

#include <CommonCrypto/CommonHMAC.h>

#import "FRAMechanism.h"

@interface FRATotpOathMechanism : FRAMechanism

#pragma mark -
#pragma mark Properties

/*!
 * The length of the OATH code generated by the mechanism. Always 6 or 8; defaults to 6.
 */
@property (nonatomic, readonly) NSUInteger codeLength;
/*!
 * The current login code for the OATH mechanism.
 */
@property (nonatomic, readonly) NSString *code;
/*!
 * The secret key bytes used by the OATH mechanism.
 */
@property (nonatomic, readonly) NSData *secretKey;
/*!
 * The algorithm used for generating the next hash code.
 */
@property (nonatomic, readonly) CCHmacAlgorithm algorithm;
/*!
 * The time period to be used when generating the next hash code.
 */
@property (nonatomic, readonly) u_int32_t period;

#pragma mark -
#pragma mark Lifecyle

/*!
 * Initialize a TOTP OATH mechanism.
 *
 * @param database The database to which this mechanism can be persisted.
 * @param identityModel The identity model which contains the list of identities.
 * @param secretKey The secret key bytes used to generate HMAC.
 * @param algorithm The HMAC algorithm to use. Currently only MD5, SHA256, SHA512 and SHA1 are supported.
 * @param codeLength The length of the code.
 * @param period TOTP based refresh period.
 *
 * @return The initialized mechanism or nil if initialization failed.
 */
- (instancetype)initWithDatabase:(FRAIdentityDatabase *)database identityModel:(FRAIdentityModel *)identityModel secretKey:(NSData *)secretKey HMACAlgorithm:(CCHmacAlgorithm)algorithm codeLength:(NSUInteger)codeLength period:(u_int32_t)period;

/*!
 * Allocate and initialize a TOTP OATH mechanism.
 *
 * @param database The database to which this mechanism can be persisted.
 * @param identityModel The identity model which contains the list of identities.
 * @param secretKey The secret key bytes used to generate HMAC.
 * @param algorithm The HMAC algorithm to use. Currently only MD5, SHA256, SHA512 and SHA1 are supported.
 * @param codeLength The length of the code.
 * @param period TOTP based refresh period.
 *
 * @return The initialized mechanism or nil if initialization failed.
 */
+ (instancetype)mechanismWithDatabase:(FRAIdentityDatabase *)database identityModel:(FRAIdentityModel *)identityModel secretKey:(NSData *)secretKey HMACAlgorithm:(CCHmacAlgorithm)algorithm codeLength:(NSUInteger)codeLength period:(u_int32_t)period;

/*!
 * Generates the next code for this OATH mechanism.
 *
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 */
- (void)generateNextCode:(NSError *__autoreleasing*)error;

/*!
 * Track the time progress of the TOTP code.
 */
- (float)progress;

/*!
 * Check whether the TOTP code has expired.
 */
- (BOOL)hasExpired;

@end
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

@class FRAFMDatabaseConnectionHelper;
@class FRAIdentity;
@class FRAIdentityModel;
@class FRAMechanism;
@class FRANotification;

/*!
 * Delegate for FRAIdentityDatabase SQL operations.
 *
 * Allows non-SQL operations of FRAIdentityDatabase to be unit tested.
 */
@interface FRAIdentityDatabaseSQLiteOperations : NSObject

#pragma mark -
#pragma Life cycle Functions

- (instancetype)initWithDatabase:(FRAFMDatabaseConnectionHelper *)database;

#pragma mark -
#pragma mark Identity Functions

/*!
 * Save the identity to the database.
 * @param identity The identity to save.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the identity is inserted in the database, otherwise NO.
 */
- (BOOL)insertIdentity:(FRAIdentity *)identity error:(NSError *__autoreleasing *)error;

/*!
 * Remove the identity from the database.
 * @param identity The identity to remove.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the identity is removed from the database, otherwise NO.
 */
- (BOOL)deleteIdentity:(FRAIdentity *)identity error:(NSError *__autoreleasing *)error;

#pragma mark -
#pragma mark Mechanism Functions

/*!
 * Save a new mechanism to the database.
 * @param mechanism The mechanism to save.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the mechanism is inserted in the database, otherwise NO.
 */
- (BOOL)insertMechanism:(FRAMechanism *)mechanism error:(NSError *__autoreleasing *)error;

/*!
 * Remove the mechanism from the database.
 * @param mechanism The mechanism to remove.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the mechanism is removed from the database, otherwise NO.
 */
- (BOOL)deleteMechanism:(FRAMechanism *)mechanism error:(NSError *__autoreleasing *)error;

/*!
 * Save changes to an existing mechanism to the database.
 * @param mechanism The mechanism to save.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the mechanism is updated in the database, otherwise NO.
 */
- (BOOL)updateMechanism:(FRAMechanism *)mechanism error:(NSError *__autoreleasing *)error;

#pragma mark -
#pragma mark Notification Functions

/*!
 * Save a new notification to the database.
 * @param notification The notification to save.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the notification is inserted in the database, otherwise NO.
 */
- (BOOL)insertNotification:(FRANotification *)notification error:(NSError *__autoreleasing *)error;

/*!
 * Remove the notification from the database.
 * @param notification The notification to remove.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the notification is removed from the database, otherwise NO.
 */
- (BOOL)deleteNotification:(FRANotification *)notification error:(NSError *__autoreleasing *)error;

/*!
 * Save changes to an existing notification to the database.
 * @param notification The notification to save.
 * @param error If an error occurs, upon returns contains an NSError object that describes the problem. If you are not interested in possible errors, you may pass in NULL.
 * @return YES if the notification is updated in the database, otherwise NO.
 */
- (BOOL)updateNotification:(FRANotification *)notification error:(NSError *__autoreleasing *)error;

@end

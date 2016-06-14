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

#import <XCTest/XCTest.h>

#import "FRAIdentityDatabase.h"
#import "FRAIdentityModel.h"
#import "FRAOathMechanismFactory.h"
#import "FRATotpOathMechanism.h"
#import "FRAUriMechanismReader.h"

@interface FRATotpAothMechanismTests : XCTestCase

@end

@implementation FRATotpAothMechanismTests {
    FRAUriMechanismReader *reader;
}

- (void)setUp {
    [super setUp];
    FRAIdentityDatabase *database = [[FRAIdentityDatabase alloc] initWithSqlOperations:nil];
    FRAIdentityModel *identityModel = [[FRAIdentityModel alloc] initWithDatabase:nil sqlDatabase:nil];
    reader = [[FRAUriMechanismReader alloc] initWithDatabase:database identityModel:identityModel];
    [reader addMechanismFactory:[[FRAOathMechanismFactory alloc] init]];
}

- (void)testMechanismCanGenerateCode {
    NSURL *qrUrl = [NSURL URLWithString:@"otpauth://totp/ForgeRock:demo?secret=EE3PFF5BM6GHVRNZIBBQWBNRLQ======&issuer=ForgeRock&digits=6&period=30"];
    
    FRATotpOathMechanism *mechanism = (FRATotpOathMechanism *)[reader parseFromURL:qrUrl error:nil];
    [mechanism generateNextCode:nil];
    
    XCTAssertGreaterThan(mechanism.code.length, 0);
}

- (void)testMechanismCodeHasntExpired {
    NSURL *qrUrl = [NSURL URLWithString:@"otpauth://totp/ForgeRock:demo?secret=EE3PFF5BM6GHVRNZIBBQWBNRLQ======&issuer=ForgeRock&digits=6&period=30"];
    
    FRATotpOathMechanism *mechanism = (FRATotpOathMechanism *)[reader parseFromURL:qrUrl error:nil];
    [mechanism generateNextCode:nil];
    
    XCTAssertGreaterThan(mechanism.progress, 0);
    XCTAssertLessThan(mechanism.progress, 1);
    XCTAssertFalse(mechanism.hasExpired);
}

- (void)testMechanismCodeHasExpired {
    NSURL *qrUrl = [NSURL URLWithString:@"otpauth://totp/ForgeRock:demo?secret=EE3PFF5BM6GHVRNZIBBQWBNRLQ======&issuer=ForgeRock&digits=6&period=1"];
    
    FRATotpOathMechanism *mechanism = (FRATotpOathMechanism *)[reader parseFromURL:qrUrl error:nil];
    [mechanism generateNextCode:nil];
    [NSThread sleepForTimeInterval:1.1f];
    
    XCTAssertEqual(mechanism.progress, 1);
    XCTAssertTrue(mechanism.hasExpired);
}

@end
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

#import "FRANotificationsTableViewController.h"
#import "FRANotificationTableViewCell.h"

@implementation FRANotificationsTableViewController

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Present notifications as a flat list not broken down into sections
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // TODO: Return count of active notifications
    return 2;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    // TODO: Lookup relevant notification from SQLite DB
    static NSString *CellIdentifier = @"NotificationCell";
    FRANotificationTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    //  cell.image = ...
    cell.issuer.text = @"ForgeRock";
    cell.shortDescription.text = @"Authorization request";
    cell.time.text = @"3 min ago";
    [cell layoutIfNeeded];
    return cell;
}

@end